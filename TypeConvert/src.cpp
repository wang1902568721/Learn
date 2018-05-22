#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <iostream>
using namespace std;
#include <mbstring.h>
#include <math.h>

#define ErrCode 102

void ItoStream(long dw, BYTE * des)
{
	des[0] = HIBYTE(HIWORD(dw));
	des[1] = LOBYTE(HIWORD(dw));
	des[2] = HIBYTE(LOWORD(dw));
	des[3] = LOBYTE(LOWORD(dw));
}
void longToByteBigEndian(long dw, BYTE * des)
{
	des[0] = LOBYTE(LOWORD(dw));
	des[1] = HIBYTE(LOWORD(dw));
	des[2] = LOBYTE(HIWORD(dw));
	des[3] = HIBYTE(HIWORD(dw));
}

void test()
{
	BYTE bVar = ErrCode;
	int iVar = bVar;
	printf("%d\n", iVar);
}

void testVector(unsigned char *ucText)
{
	vector<unsigned char> vText;
	vText.assign(ucText, ucText + _mbstrlen((char *)ucText));
	for (int i = 0; i < _mbslen(ucText); i++)
	{
		cout << vText[i]<<endl;
	}
	//vText(ucText, ucText + strlen(ucText));
}

//iLength从1开始计数
void ReverseStr(unsigned char *strToReverse,int iLength)
{
	if (NULL == strToReverse)
	{
		return;
	}
	if (1 == iLength)
	{
		return;
	}
	for (int iIndex = 0; iIndex < iLength/2; iIndex++)
	{
		unsigned char ucVar = strToReverse[iIndex];
		strToReverse[iIndex] = strToReverse[iLength - iIndex-1];
		strToReverse[iLength - iIndex - 1] = ucVar;
	}
}
/*
*/
int HexStrToBCD(vector<unsigned char> &vHexStr,unsigned char *pStrResult,int iLength)
{
	int iLengthVar = 0;
	int iNum = 0;
	unsigned char *ucBcdArr = NULL;
	int iIndex = 0;
	bool bFlag = true;

	//计算折合后的实际长度
	iLengthVar = vHexStr.size();
	if (0 == iLength % 2)
	{
		iNum = iLengthVar / 2;
	}
	else
	{
		iNum = iLengthVar / 2 + 1;
	}
	ucBcdArr = (unsigned char *)malloc(iNum * sizeof(unsigned char)); 
	if (NULL == ucBcdArr)
	{
		return 0;
	}
	memset(ucBcdArr, 0x00, iNum);
	vector<unsigned char>::iterator itV;

	for (itV = vHexStr.begin(); itV != vHexStr.end(); itV++)
	{
		BYTE bVar = *itV;
		if (true == bFlag)
		{
			ucBcdArr[iIndex] = (ucBcdArr[iIndex] | bVar);
			bFlag = false;
		}
		else
		{
			ucBcdArr[iIndex] = (ucBcdArr[iIndex] | (bVar << 4));
			iIndex++;
			bFlag = true;
		}
	}
	ReverseStr(ucBcdArr,iNum);
	
	//避免给与的字符数组长度小于实际转换后的长度，产生截断
	iLengthVar = iNum < iLength ? iNum: iLength;
	for (iIndex = 0; iIndex < iLengthVar; iIndex++)
	{
		*(pStrResult + iLength-1 - iIndex) = *(ucBcdArr + iNum-1 - iIndex);
	}
	free(ucBcdArr);
	return iLengthVar;
}
/*
参数：
	iInput:待转换的十进制数
	pStrResult：存储转换后的BCD码字符串
	iLength：pStrResult的实际长度，从1开始计算
返回值：
	实际有效的长度
备注：
	如果pStrResult的长度大于实际转换的长度，则结果从高位至低位存放
*/
int DecToBCD(int iInput,unsigned char *pStrResult,int iLength)
{
	int iIndex;
	int iCalcNum;
	vector<unsigned char> vHexStr;

	iCalcNum = iInput;
	while ( ((iCalcNum / 16) >=0) && (0 != iCalcNum))
	{
		int iNum = iCalcNum % 16;
		if (iNum >= 0 && iNum < 10)
		{
			vHexStr.push_back(iNum);
		}
		else
		{
			switch (iNum)
			{
			case 10:
				vHexStr.push_back(0x0A);
				break;
			case 11:
				vHexStr.push_back(0x0B);
				break;
			case 12:
				vHexStr.push_back(0x0C);
				break;
			case 13:
				vHexStr.push_back(0x0D);
				break;
			case 14:
				vHexStr.push_back(0x0E);
				break;
			case 15:
				vHexStr.push_back(0x0F);
				break;
			}
		}
		iCalcNum = iCalcNum / 16;
	}
	return HexStrToBCD(vHexStr,pStrResult,iLength);
}

/*
16进制BCD码转十进制
*/
long BCDHexStr2Dec(vector<unsigned char> &vToConvert)
{
	unsigned char ucVar;
	unsigned char ucHigh;
	unsigned char ucLow;
	int iIndex;
	int iTemp;
	long lRet;

	lRet = 0;
	iIndex = 0;
	while (!vToConvert.empty())
	{
		ucVar = vToConvert.back();
		ucHigh = ((ucVar >> 4) & 0x0F);
		ucLow = (ucVar & 0x0F);

		if (ucLow >= 0x00 && ucLow <= 0x09)
		{
			iTemp = ucLow - 0x00;
		}
		if (ucLow >= 0x0A && ucLow <= 0x0F)
		{
			iTemp = ucLow - 0x0A + 10;
		}
		lRet = lRet + iTemp * pow(16, iIndex);
		iIndex++;

		if (ucHigh >= 0x00 && ucHigh <= 0x09)
		{
			iTemp = ucHigh - 0x00;
		}
		if (ucHigh >= 0x0A && ucHigh <= 0x0F)
		{
			iTemp = ucHigh - 0x0A + 10;
		}
		lRet = lRet + iTemp * pow(16, iIndex);
		iIndex++;

		vToConvert.pop_back();
	}
	return lRet;
}
int main()
{
	vector<unsigned char> vec;
	vec.push_back(0x00);
	vec.push_back(0xF1);

	cout<<BCDHexStr2Dec(vec)<<endl;
	cout << pow(2,4) << endl;
	system("pause");
	return 0;
}