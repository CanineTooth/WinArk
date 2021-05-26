// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER		0x0601
#define _WIN32_WINNT	0x0601
#define _WIN32_IE	0x0700
#define _RICHEDIT_VER	0x0500

#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

#include <string>
#include <unordered_map>
#include <memory>
#include <winternl.h>

#include <atlstr.h>

#include <wil\resource.h>
#include <atlframe.h>
// 这里有字符串定义，所以atlstr.h在前面
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlddx.h>

#include <strsafe.h>
#include <atlctrlx.h>
#include <atlctrlw.h>
#include <atlmisc.h>
#include <atlcrack.h>
#include <atltime.h>
#include <atlcoll.h>
#include <atlsplit.h>


#include "ThemeSystem.h"
#include "WinSysCore.h"


extern int g_AvHighFont;
extern int g_AvWidthFont;
extern HFONT g_hOemFixedFont;

extern HPEN g_hBlackPen, g_hWhitePen, g_hDarkGrayPen;
extern HPEN g_myPen[20];

extern COLORREF g_crLightGray, g_crDarkGray, g_crBlack;
extern COLORREF g_myColor[20];

extern HBRUSH g_hLightGrayBrush;

extern HWND g_hModuleFrm, g_hWndMDIClient, g_hWndTop;

extern HBRUSH g_myBrush[20];

extern t_scheme g_myScheme[8];


#if defined _M_IX86
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
