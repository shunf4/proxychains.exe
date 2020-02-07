﻿#include "hookdll_win32.h"
#include "hookdll_interior_win32.h"
#include "log_win32.h"
#include <MinHook.h>

void Win32HookWs2_32(void)
{
	HMODULE hWs2_32;
	LPVOID pWs2_32_WSAStartup = NULL;
	LPVOID pWs2_32_WSAConnect = NULL;
	LPVOID pWs2_32_connect = NULL;
	LPVOID pWs2_32_gethostbyname = NULL;
	LPVOID pWs2_32_gethostbyaddr = NULL;
	LPVOID pWs2_32_getaddrinfo = NULL;
	LPVOID pWs2_32_GetAddrInfoW = NULL;
	LPVOID pWs2_32_GetAddrInfoExA = NULL;
	LPVOID pWs2_32_GetAddrInfoExW = NULL;
	LPVOID pWs2_32_freeaddrinfo = NULL;
	LPVOID pWs2_32_FreeAddrInfoW = NULL;
	LPVOID pWs2_32_FreeAddrInfoEx = NULL;
	LPVOID pWs2_32_FreeAddrInfoExW = NULL;
	LPVOID pWs2_32_getnameinfo = NULL;
	LPVOID pWs2_32_GetNameInfoW = NULL;

	LoadLibraryW(L"ws2_32.dll");

	if ((hWs2_32 = GetModuleHandleW(L"ws2_32.dll"))) {
		pWs2_32_WSAStartup = GetProcAddress(hWs2_32, "WSAStartup");
		pWs2_32_WSAConnect = GetProcAddress(hWs2_32, "WSAConnect");
		pWs2_32_connect = GetProcAddress(hWs2_32, "connect");
		pWs2_32_gethostbyname = GetProcAddress(hWs2_32, "gethostbyname");
		pWs2_32_gethostbyaddr = GetProcAddress(hWs2_32, "gethostbyaddr");
		pWs2_32_getaddrinfo = GetProcAddress(hWs2_32, "getaddrinfo");
		pWs2_32_GetAddrInfoW = GetProcAddress(hWs2_32, "GetAddrInfoW");
		pWs2_32_GetAddrInfoExA = GetProcAddress(hWs2_32, "GetAddrInfoExA");
		pWs2_32_GetAddrInfoExW = GetProcAddress(hWs2_32, "GetAddrInfoExW");
		pWs2_32_freeaddrinfo = GetProcAddress(hWs2_32, "freeaddrinfo");
		pWs2_32_FreeAddrInfoW = GetProcAddress(hWs2_32, "FreeAddrInfoW");
		pWs2_32_FreeAddrInfoEx = GetProcAddress(hWs2_32, "FreeAddrInfoEx");
		pWs2_32_FreeAddrInfoExW = GetProcAddress(hWs2_32, "FreeAddrInfoExW");
		pWs2_32_getnameinfo = GetProcAddress(hWs2_32, "getnameinfo");
		pWs2_32_GetNameInfoW = GetProcAddress(hWs2_32, "GetNameInfoW");
	}

	// Another hook on ConnectEx() will take effect at WSAStartup()
	CREATE_HOOK3_IFNOTNULL(Ws2_32, WSAStartup, pWs2_32_WSAStartup);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, WSAConnect, pWs2_32_WSAConnect);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, connect, pWs2_32_connect);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, gethostbyname, pWs2_32_gethostbyname);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, gethostbyaddr, pWs2_32_gethostbyaddr);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, getaddrinfo, pWs2_32_getaddrinfo);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, GetAddrInfoW, pWs2_32_GetAddrInfoW);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, GetAddrInfoExA, pWs2_32_GetAddrInfoExA);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, GetAddrInfoExW, pWs2_32_GetAddrInfoExW);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, freeaddrinfo, pWs2_32_freeaddrinfo);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, FreeAddrInfoW, pWs2_32_FreeAddrInfoW);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, FreeAddrInfoEx, pWs2_32_FreeAddrInfoEx);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, FreeAddrInfoExW, pWs2_32_FreeAddrInfoExW);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, getnameinfo, pWs2_32_getnameinfo);
	CREATE_HOOK3_IFNOTNULL(Ws2_32, GetNameInfoW, pWs2_32_GetNameInfoW);
}

void CygwinHook(void)
{
	HMODULE hCygwin1;
	LPVOID pCygwin1_connect = NULL;

	LoadLibraryW(L"cygwin1.dll");

	if ((hCygwin1 = GetModuleHandleW(L"cygwin1.dll"))) { pCygwin1_connect = GetProcAddress(hCygwin1, "connect"); }

	CREATE_HOOK3_IFNOTNULL(Cygwin1, connect, pCygwin1_connect);
}
