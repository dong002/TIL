#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <io.h>
#include <windows.h>
#include <windows.h>
#include <string.h>
#include <io.h>
#define spot GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&presentCur)
#define CX presentCur.dwCursorPosition.X
#define CY presentCur.dwCursorPosition.Y
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13


void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
int main() {
	//	int n[4] = { 0 }; // À·
	//	int result = 0, N; // ³« È®·ü,À·À» ´øÁø°á°ú
	//	srand(time(NULL));
	//	int key = _getch(); // ½ºÆäÀÌ½º¹Ù ÀÔ·Â
	//	int y[4] = { 0 };
	//	if (key == 32) {
	//		for (int i = 0; i != 4; i++) // À· ´øÁö±â
	//			n[i] = rand() % 2;
	//		N = rand() % 20; // ³« È®·ü 5%
	//		int yut = n[0] + n[1] + n[2] + n[3];
	//		if (N == 1)
	//			result = 0;
	//		else {
	//			switch (yut) {
	//			case 1:
	//				if (n[0] == 1)
	//					result = -1;
	//				else
	//					result = 1;
	//				break;
	//			case 2:result = 2; break;
	//			case 3:result = 3; break;
	//			case 4:result = 4; break;
	//			}
	//		}
	//	}
	//	if (result == -1) {
	//		y[0] = 1;
	//	}
	//	else {
	//		for (int i = 1; i <= result; i++) {
	//			y[i] = 1;
	//		}
	//	}
		//if(n==1)
		/*for (int j = 0; j < 4; j++) {
			if (y[j] == 1) {
				if (j == 0) {
					printf("¦£¦¡¦¤\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢¦«¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¦¦¡¦¥\n");
					if (j != 3)
						printf("\x1b[%dA", 8);
				}
				else {
					printf("¦£¦¡¦¤\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¦¦¡¦¥\n");
					if (j != 3)
						printf("\x1b[%dA", 8);
				}
			}
			else {
				printf("¦£¦¡¦¤\n¦¢¦«¦¢\n¦¢ ¦¢\n¦¢¦«¦¢\n¦¢ ¦¢\n¦¢¦«¦¢\n¦¦¦¡¦¥\n");
				if (j != 3)
					printf("\x1b[%dA", 8);
			}
		}*/
		/*for (int j = 0; j < 4; j++) {
			COORD pos = { j*3, 0 };
			if (y[j] == 1) {
				if (j == 0) {

					printf("¦£¦¡¦¤\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢¦«¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¦¦¡¦¥\n");
					if (j != 3)
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				}
				else {
					printf("¦£¦¡¦¤\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¢ ¦¢\n¦¦¦¡¦¥\n");
					if (j != 3)
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				}
			}
			else {
				printf("¦£¦¡¦¤\n¦¢¦«¦¢\n¦¢ ¦¢\n¦¢¦«¦¢\n¦¢ ¦¢\n¦¢¦«¦¢\n¦¦¦¡¦¥\n");
				if (j != 3) {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				}
			}


		}*/
	cursor(20, 10);
}
	void Cursor(int x, int y) {
		while (1) {
			gotoxy(x, y);
			int key;
			key = _getch();
			if (key == 224) {
				key = _getch();
				switch (key) {
				case LEFT:
					if (x != 0)
						x--;
					break;
				case RIGHT:
					x++;
					break;
				case UP:
					if (y != 0)
						y--;
					break;
				case DOWN:
					y++;
					break;
				}
			}
			else if (key == 13) {
				printf("%d%d", CX, CY);
			}
		}
	}

