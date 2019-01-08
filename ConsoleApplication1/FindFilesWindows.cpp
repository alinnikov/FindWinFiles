#include "pch.h"
#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <string>

using namespace std;


int main(void)
{
	TCHAR buff[MAX_PATH * 2];
	buff[0] = 0;
	GetSystemWindowsDirectory(buff, sizeof(buff));

	wstring windows(&buff[0]);
	wcout << L"Your path: " << windows + L"\\*" << endl;

	WIN32_FIND_DATAW wfd;

	HANDLE const hFind = FindFirstFileW((L"\\\\?\\" + windows + L"\\*").c_str(), &wfd);

	if (INVALID_HANDLE_VALUE != hFind)
	{
		do
		{
			wcout << &wfd.cFileName[0] << endl;
		} while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}
	else {
		printf("FindFirstFile failed (%d)\n", GetLastError());
		return 0;
	}
}