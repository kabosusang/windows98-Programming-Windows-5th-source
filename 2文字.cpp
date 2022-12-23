#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <wchar.h>
#include <wingdi.h>

LRESULT CALLBACK WndProc(HWND, UINT ,WPARAM, LPARAM);


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
PSTR szCmdLine, int iCmdshow
 )
 {
    static TCHAR szAppName[] = TEXT("HElloWin");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style  = CS_HREDRAW | CS_VREDRAW; //水平和垂直要改变时要完全重画

    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    
    wndclass.hIcon = LoadIcon(0, IDI_WARNING);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    //wndclass.hbrBackground = (HBRUSH)NULL_BRUSH;
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName; 

    if(!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program require Windows NT!"),szAppName, MB_ICONERROR);

        return 0;
    }
    hwnd = CreateWindow( szAppName, // window class name 
 TEXT ("The Hello Program"), // window caption 
 WS_OVERLAPPEDWINDOW, // window style 
 CW_USEDEFAULT, // initial x position 
 CW_USEDEFAULT, // initial y position 
 CW_USEDEFAULT, // initial x size 
 CW_USEDEFAULT, // initial y size 
 NULL, // parent window handle 
 NULL, // window menu handle 
 hInstance, // program instance handle 
 NULL) ; // creation parameters 
 
ShowWindow (hwnd, iCmdshow) ;  //iCmdshow 传给WinMain 
UpdateWindow (hwnd) ;  //重画显示区域
 
while (GetMessage (&msg, NULL, 0, 0))  /*第二、第三
和第四个参数设定为 NULL 或者 0，表示程式接收它自己建立的所有视窗的所有
讯息。*/
 { 
 TranslateMessage (&msg) ;  //将 msg 结构传给 Windows，进行一些键盘转换
 DispatchMessage (&msg) ;  //又将 msg 结构回传给 Windows。
 } 
return msg.wParam ; 
} 
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)  //参数与MSG前四个参数相同
{ 
HDC hdc ;//装置内容代号; 
HDC Hdc_1;
PAINTSTRUCT ps ; 
RECT rect ; 
TEXTMETRIC tm;
 
static int cxChar, cyChar ,cxCaps;  //定义变量
int iLength =0;
const wchar_t* szBuffer = new wchar_t[20];
szBuffer = L"Wecome To Text";

switch (message) 
 { 
case WM_CREATE: 
    //PlaySound(L"hellowin.wav", NULL, SND_FILENAME | SND_ASYNC) ; 
   Hdc_1 = GetDC(hwnd);

   GetTextMetrics(Hdc_1,&tm);
   
   cxChar = tm.tmAveCharWidth ; 
   cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2 ;
   cyChar = tm.tmHeight + tm.tmExternalLeading ;

   iLength = wcslen(szBuffer);
   TextOutW (Hdc_1, 10, 10, szBuffer, iLength) ;
 

   ReleaseDC(hwnd,Hdc_1);

    return 0 ; 
case WM_PAINT:  //UpdateWindow呼叫时启用   CS_HREDRAW 和 CS_VREDRAW也会启用
    //InvalidateRect (hwnd, NULL, TRUE) ;  擦除背景
    hdc = BeginPaint (hwnd, &ps) ; 
 
    GetClientRect (hwnd, &rect) ; //获取窗口大小
     
    DrawTextA(hdc,"Hello, Windows 98!", -1, &rect, 
    DT_SINGLELINE | DT_CENTER | DT_VCENTER) ; 
    
    EndPaint (hwnd, &ps) ; 
    return 0 ; 
 
case WM_DESTROY: 
    PostQuitMessage (0) ; 

    
 return 0 ; 
 } 
 return DefWindowProc (hwnd, message, wParam, lParam) ;  //不处理的消息应该传回
} 