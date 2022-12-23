#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <wchar.h>
#include <mmsystem.h> 
#pragma comment(lib, "D:\\vc6++\\Microsoft Visual Studio\\VC98\\Lib\\WinMM.Lib")

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
    wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
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
PAINTSTRUCT ps ; 
RECT rect ; 
 
switch (message) 
 { 
case WM_CREATE: 
    //PlaySound(L"hellowin.wav", NULL, SND_FILENAME | SND_ASYNC) ; 
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

 