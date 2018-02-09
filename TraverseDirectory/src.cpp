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
		//��ȡ�ļ�����
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
		//��ȡ����
		_stprintf(szNewFilename, TEXT("%ls%ls.%ls"), TEXT("��̽���ʽܵ�����"), szEp, szFileType);
		//return _trename(szOldFilename, szNewFilename);
	}
	else
	{
		//��ƥ����ļ�����
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

	//��������·��
	_stprintf(szSearchPath, TEXT("%ls\\*"), szDir);

	hFindHandle = FindFirstFile(szSearchPath, &stFindData);
	if (INVALID_HANDLE_VALUE == hFindHandle)
	{
		cout << "FindFirstFile error [" << GetLastError() << "]" << endl;
		return -1;
	}

	do
	{
		//�ļ��еĴ�����
		if (FILE_ATTRIBUTE_DIRECTORY == (stFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			if (FILE_ATTRIBUTE_SYSTEM == (stFindData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM))
			{
				//ϵͳ�ļ���
			}
			else
			{
				//��ϵͳ�ļ���
				setlocale(LC_ALL, "chs");
				wcout << stFindData.cFileName << endl;
			}
		}
		else
		{
			//�ļ��Ĵ�����
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

	//��ȡ����·��
	cout << "���������·��������D:\\Downloads����";
	setlocale(LC_ALL, "chs");
	wcin.getline(szFilePath, MAX_PATH);

	SearchDirectory(szFilePath);

	system("pause");
	return 0;
}