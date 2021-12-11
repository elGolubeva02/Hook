#include <Windows.h>
#include <stdio.h>
#define PATH L"X:\\Doc.csv"
#define RUS 1049
#define ENG 1033
#define SIZE_STR 20

LRESULT CALLBACK LogMouse(int iCode, WPARAM wParam, LPARAM lParam);
VOID WriteToFile(LPWSTR wstr);
DWORD LKey = 0, RKey = 0, CKey = 0, TKey = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE HpREViNSTANCE, PSTR pCmdLine, int nCmdShow)
{
	HHOOK hHook = SetWindowsHookExW(WH_MOUSE_LL, LogMouse, NULL, NULL);
	MSG msg = { 0 };
	while (GetMessageW(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UnhookWindowsHookEx(hHook);
	return 0;
}

LRESULT CALLBACK LogMouse(int iCode, WPARAM wParam, LPARAM lParam)
{
	LPWSTR wstr=(LPWSTR)calloc(150, sizeof(WCHAR));
	POINT p;
	SYSTEMTIME tim;
	if (wParam == 513)
	{
		GetCursorPos(&p);
		GetLocalTime(&tim);
		swprintf(wstr, 150, L"%d; %d; %d:%d\n", p.x, p.y, tim.wHour, tim.wMinute);
		WriteToFile(wstr);
		free(wstr);
	}
	if (wParam == 516)
	{
		GetCursorPos(&p);
		GetLocalTime(&tim);
		swprintf(wstr, 150, L"%d; %d; %d:%d\n", p.x, p.y, tim.wHour, tim.wMinute);
		WriteToFile(wstr);
		free(wstr);
	}
	if (wParam == 520)
	{
		GetCursorPos(&p);
		GetLocalTime(&tim);
		swprintf(wstr, 150, L"%d; %d; %d:%d\n", p.x, p.y, tim.wHour, tim.wMinute);
		WriteToFile(wstr);
		free(wstr);
	}
	return CallNextHookEx(NULL, iCode, wParam, lParam);
}

VOID WriteToFile(LPWSTR wstr)
{
	FILE* f = NULL;
	if (!_wfopen_s(&f, PATH, L"ab"))
	{
		fwrite(wstr, sizeof(WCHAR), wcslen(wstr), f);
		fclose(f);
	}
}


