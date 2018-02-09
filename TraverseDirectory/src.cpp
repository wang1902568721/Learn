#include <windows.h>
#include <tchar.h>
#include <AtlConv.h>
#include <iostream>
using namespace std;

int RenameFile(TCHAR *szOldFilename)
{
	TCHAR szNewFilename[MAX_PATH];
	TCHAR szFileType[10];
	TCHAR szEp[3];
	int iLength = 0;
	TCHAR *tpPos = NULL;

	ZeroMemory(szNewFilename, MAX_PATH);
	ZeroMemory(szFileType, 10);
	ZeroMemory(szEp, 3);

	iLength = _tcslen(szOldFilename);
	if (NULL != _tcsstr(szOldFilename + (iLength - 5), TEXT(".MKV")) || NULL != _tcsstr(szOldFilename + (iLength - 5), TEXT(".rmvb")))
	{
		//获取文件类型
		tpPos == _tcsstr(szOldFilename + (iLength - 5), TEXT(".mkv"));
		if (NULL != tpPos)
		{
			_tcsncpy(szFileType, tpPos, _tcslen(TEXT(".mkv")));
		}
		else
		{
			tpPos == _tcsstr(szOldFilename + (iLength - 5), TEXT(".rmvb"));
			if (NULL != tpPos)
			{
				_tcsncpy(szFileType, tpPos, _tcslen(TEXT(".mkv")));
			}
			else
			{
				return -1;
			}
		}
		//获取集数
		_stprintf(szNewFilename, TEXT("%ls%ls.%ls"), TEXT("神探狄仁杰第三部"), szEp, szFileType);
		//return _trename(szOldFilename, szNewFilename);
	}
	else
	{
		//不匹配的文件类型
		return -1;
	}

	return 0;
}

int SearchDirectory(TCHAR *szDir)
{
	WIN32_FIND_DATA stFindData;
	HANDLE hFindHandle;
	TCHAR szSearchPath[MAX_PATH];
	TCHAR szFileLocation[MAX_PATH];

	ZeroMemory(szSearchPath, MAX_PATH);
	ZeroMemory(szFileLocation, MAX_PATH);

	//调整搜索路径
	_stprintf(szSearchPath, TEXT("%ls\\*"), szDir);

	hFindHandle = FindFirstFile(szSearchPath, &stFindData);
	if (INVALID_HANDLE_VALUE == hFindHandle)
	{
		cout << "FindFirstFile error [" << GetLastError() << "]" << endl;
		return -1;
	}

	do
	{
		//文件夹的处理方法
		if (FILE_ATTRIBUTE_DIRECTORY == (stFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			if (FILE_ATTRIBUTE_SYSTEM == (stFindData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM))
			{
				//系统文件夹
			}
			else
			{
				//非系统文件夹
				setlocale(LC_ALL, "chs");
				wcout << stFindData.cFileName << endl;
			}
		}
		else
		{
			//文件的处理方法
			//setlocale(LC_ALL, "chs");
			//_tprintf(TEXT("%ls\n"), stFindData.cFileName);

			ZeroMemory(szFileLocation, MAX_PATH);
			_stprintf(szFileLocation, TEXT("%ls\\%ls"), szDir, stFindData.cFileName);
			RenameFile(szFileLocation);
		}

	} while (FALSE != FindNextFile(hFindHandle,&stFindData));

	FindClose(hFindHandle);

	return 0;
}



int main()
{
	TCHAR szFilePath[MAX_PATH];

	ZeroMemory(szFilePath, MAX_PATH);

	//获取搜索路径
	cout << "请输入检索路径（类似D:\\Downloads）：";
	setlocale(LC_ALL, "chs");
	wcin.getline(szFilePath, MAX_PATH);

	SearchDirectory(szFilePath);

	system("pause");
	return 0;
}