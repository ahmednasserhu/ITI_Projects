#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define BACKSPACE 8
#define ESC 27
#define ADD 43
#define MAX_SIZE 50

int position = 0;
int length = 0;
char ch;
char string[MAX_SIZE];

void SetColor(int ForgC);
void gotoxy(int x, int y);
void delete_element(char *string);
int string_length(char array2[]);
void line_editor();
void operation(char c);
void design();

void line_editor() {
    gotoxy(0, 0);
    printf("=================line editor=====================");
    gotoxy(0, 4);
    printf("=================================================");
    operation(ch);
}

void design() {
    gotoxy(0, 0);
    printf("=================line editor=====================");
    gotoxy(0, 4);
    printf("=================================================");
    gotoxy(0, 2);
}

int main() {
    line_editor();
    return 0;
}

void operation(char c) {
    gotoxy(0, 2);
    while (1) {
        fflush(stdin);
        ch = getch();
        fflush(stdin);

        if (ch == -32) {
            ch = getch();  // Extended
            switch ((int)ch) {
                case LEFT_ARROW:
                    position--;
                    if (position < 0) {
                        position = 0;
                    }
                    gotoxy(position, 2);
                    break;
                case RIGHT_ARROW:
                    position++;
                    if (position > length && position < MAX_SIZE) {
                        position = length;
                    }
                    gotoxy(position, 2);
                    break;
            }
        } else {
            int length = string_length(string);
            if ((ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == ' ') && length <= MAX_SIZE) {
                string[position] = ch;
                gotoxy(position, 2);
                system("cls");
                design();
                printf("%s", string);
                position++;
            } else {
                switch ((int)ch) {
                    case BACKSPACE:
                        position--;
                        if (position < 0) {
                            position = 0;
                        }
                        delete_element(string);
                        system("cls");
                        design();
                        printf("%s", string);
                        gotoxy(position, 2);
                        break;
                    case ESC:
                        exit(0);
                        break;
                }
            }
        }
    }
}

void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delete_element(char *string) {
    int length = string_length(string);
    for (int i = position; i <= length; i++) {
        if (i == length - 1) {
            string[i] = '\0';
        }
        string[i] = string[i + 1];
    }
}

int string_length(char array2[]) {
    int length = 0;
    while (array2[length] != '\0') {
        length++;
    }
    return length;
}
