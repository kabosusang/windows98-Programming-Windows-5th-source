#include <windows.h> 
#include <math.h> 


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ; 
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
 PSTR szCmdLine, int iCmdShow) 
{ 
static TCHAR szAppName[] = TEXT ("SineWave") ; 
HWND hwnd ; 


MSG msg ; 
WNDCLASS wndclass ; 
 
wndclass.style = CS_HREDRAW | CS_VREDRAW ; 
wndclass.lpfnWndProc= WndProc ; 
wndclass.cbClsExtra = 0 ; 
wndclass.cbWndExtra = 0 ; 
wndclass.hInstance = hInstance ; 
wndclass.hIcon = LoadIcon (NULL, IDI_APPLICATION) ; 
wndclass.hCursor = LoadCursor (NULL, IDC_ARROW) ; 
wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ; 
wndclass.lpszMenuName = NULL ; 
wndclass.lpszClassName = szAppName ; 
 
if (!RegisterClass (&wndclass)) 
{ 
 MessageBox ( NULL, TEXT ("Program requires Windows NT!"), 
 szAppName, MB_ICONERROR) ; 
 return 0 ; 
} 
 
hwnd = CreateWindow ( szAppName, TEXT ("Sine Wave Using Polyline"), 
 WS_OVERLAPPEDWINDOW, 
 CW_USEDEFAULT, CW_USEDEFAULT, 
 CW_USEDEFAULT, CW_USEDEFAULT, 
 NULL, NULL, hInstance, NULL) ; 
ShowWindow (hwnd, iCmdShow) ; 
UpdateWindow (hwnd) ; 
 
while (GetMessage (&msg, NULL, 0, 0)) 
 { 
 TranslateMessage (&msg) ; 
 DispatchMessage (&msg) ; 
} 
 return msg.wParam ; 
} 
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{ 
static int cxClient, cyClient ; 
HDC hdc ; 
int i ; 
PAINTSTRUCT ps ; 
static HGDIOBJ  hobj1,hobj2,hobj3;
static HPEN hPen1, hPen2, hPen3 ; 
COLORREF Pencolor;
LOGPEN logpen ; 

switch (message) 
{ 
case WM_SIZE: 


 cxClient = LOWORD (lParam) ; 
 cyClient = HIWORD (lParam) ; 
 return 0 ; 
 
case WM_PAINT: 
 hdc = GetDC (hwnd) ;
 //hobj = GetStockObject(WHITE_PEN);  //取得画笔的代号
 //SelectObject (hdc, hobj) ; 
 //SelectObject (hdc, GetStockObject (WHITE_PEN)) ; //恢复黑色

hPen1 = CreatePen (PS_SOLID, 1, 0) ; 
hPen2 = CreatePen (PS_SOLID, 3, RGB (255, 0, 0)) ; 
hPen3 = CreatePen (PS_DOT, 0, 0) ; 

hobj1 = SelectObject (hdc, hPen1) ; //装入装置内容
hobj2 = SelectObject (hdc, hPen2) ;
hobj3 = SelectObject (hdc, hPen3) ;

//hpen = CreatePenIndirect(&logpen);




 ReleaseDC(hwnd,hdc);

 return 0 ; 
 

case WM_DESTROY: 
DeleteObject (hobj1) ; 
DeleteObject (hobj2) ; 
DeleteObject (hobj3) ;

 PostQuitMessage (0) ; 
 return 0 ; 
 } 
return DefWindowProc (hwnd, message, wParam, lParam) ; 
} 