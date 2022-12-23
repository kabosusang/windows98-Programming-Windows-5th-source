#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <wchar.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
PSTR szCmdLine, int iCmdshow
 )
 {
    MessageBox(NULL, TEXT("Hello,Windows 98!"),TEXT("HelooMs") ,MB_YESNO|MB_ICONQUESTION);

    char szBuffer[100];
    sprintf(szBuffer,"The sum of %i and %i is %i",5,3,5+3);
    puts(szBuffer);

    std::cout<< "HEllow";
    return 0;
 }