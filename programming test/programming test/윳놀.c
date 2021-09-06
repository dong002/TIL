#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void Cursor(int x, int y);
int throwyut();
void start();
int CNT = 1;
void turncheck(int x);
void gotoxy();
void CursorView();
void yutcursor(int* x);
void visual(int yutbord[11][11],int red[4],int blue[4]);
int yutbord[11][11] = { {1,6,3,6,3,6,3,6,3,6,1},{2,4,0,0,0,0,0,0,0,5,2},{3,0,3,0,0,0,0,0,3,0,3},{2,0,0,4,0,0,0,5,0,0,2},{3,0,0,0,3,0,3,0,0,0,3},{2,0,0,0,0,1,0,0,0,0,2},{3,0,0,0,5,0,4,0,0,0,3},{2,0,0,3,0,0,0,3,0,0,2},{3,0,5,0,0,0,0,0,4,0,3},{2,3,0,0,0,0,0,0,0,3,2}, {1,6,3,6,3,6,3,6,3,6,1} };
int enemycheck(int x, int y, int s);
	int main() {
		CursorView();
		CONSOLE_SCREEN_BUFFER_INFO presentCur;
		int yut;
		int n = 0;
		int red[4] = { 1,1,1,1 };
		int blue[4] = { 2,2,2,2 };
		int fx=0,fy=0,fsr=1,fsb=1;
		start();
		while (1) {
			if (_getch() == 32) {
				system("cls");
				break;
			}
		}// 시작화면 넘어가는 코드
		visual(yutbord,red,blue);
		while (1) {
			printf("%d번째 턴!\nSpaceBar를 눌러서 윷을 던지세요!\n", CNT); // 턴 알려줌
			yut=throwyut();
			 // 현재 말 표현
			
			/*system("cls");*/
		//n = throw();
		//look(n);
			
			while (1) {
				Cursor(20, 10);
				spot;
				fx = CX; fy = CY;
				if (yutbord[fy][fx / 2] == 7 && CNT % 2 == 1) {
					Cursor(20, 10);
					spot;
					yutbord[fy][fx / 2] = fsr;
					fsr = yutbord[CY][CX / 2];
					yutbord[CY][CX / 2] = 7;
					visual(yutbord, red, blue);
					break;
				}
				else if (yutbord[CY][CX / 2] == 8 && CNT % 2 == 0) {
					Cursor(20, 10);
					spot;
					yutbord[10][10] = fsb;
					fsb = yutbord[CY][CX / 2];
					yutbord[CY][CX / 2] = 8;
					visual(yutbord, red, blue);
					break;
				}
				else if (((CX == 26 && CY == 1) || (CX == 28 && CY == 1) || (CX == 30 && CY == 1) || (CX == 32 && CY == 1)) && CNT % 2 == 1) {
					yutbord[10][10] = 7;
					for (int i = 0; i < 4; i++) {
						if (red[i] == 1) {
							red[i] = 0;
							break;
						}
					}
					system("cls");
					visual(yutbord, red, blue);
					Cursor(20, 10);
					spot;
					yutbord[CY][CX / 2] = 7;
					yutbord[10][10] = 1;
					visual(yutbord, red, blue);
					break;
				}
				else if (((CX == 26 && CY == 2) || (CX == 28 && CY == 2) || (CX == 30 && CY == 2) || (CX == 32 && CY == 2)) && CNT % 2 == 0) {
					yutbord[10][10] = 8;
					for (int i = 0; i < 4; i++) {
						if (blue[i] == 2) {
							blue[i] = 0;
							break;
						}
					}
					system("cls");
					visual(yutbord, red, blue);
					Cursor(20, 10);
					spot;
					yutbord[CY][CX / 2] = 8;
					yutbord[10][10] = 1;
					visual(yutbord, red, blue);
					break;
				}
				else {
					gotoxy(26, 3);
					printf("잘못된선택");
					continue;
				}
	
			}
				
			while (1) {
				if (_getch() == 32) {// 스페이스바 입력
					system("cls");
					visual(yutbord, red, blue);
					break;
				}
				else if (_getch() != 32) {
					continue;
				}
			}
			if (yut == 4 || yut == 5) {
				turncheck(0);
			}
			else
				turncheck(1);
		}
			
	}
		
	int throwyut() {
		int n[4] = { 0 }; // 윷
		int result = 0;// 윷을 던진결과
		srand(time(NULL));
		int yut=0;
		// 스페이스바 입력
		if (_getch() == 32) {
			for (int i = 0; i != 4; i++) // 윷 던지기
				n[i] = rand() % 2;
			yut = n[0] + n[1] + n[2] + n[3];
			
			switch (yut) {
			case 0:result = 5; break;
			case 1:
				if (n[0] == 1)
					result = -1;
				else
					result = 1;
				break;
			case 2:result = 2; break;
			case 3:result = 3; break;
			case 4:result = 4; break;
			}
		}
		switch (result) {
		case -1:
			printf("┌─┐ ┌─┐ ┌─┐ ┌─┐ \n");
			printf("│┼│ │┼│ │┼│ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │┼│ │┼│ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │┼│ │ │ \n");
			printf("└─┘ └─┘ └─┘ └─┘ \n");
			printf("뺵도!\n");
			break;
		case 1:
			printf("┌─┐ ┌─┐ ┌─┐ ┌─┐ \n");
			printf("│┼│ │┼│ │┼│ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │┼│ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │┼│ │ │ \n");
			printf("└─┘ └─┘ └─┘ └─┘ \n");
			printf("도\n");

			break;
		case 2:
			printf("┌─┐ ┌─┐ ┌─┐ ┌─┐ \n");
			printf("│┼│ │┼│ │ │ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │ │ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │ │ │ │ \n");
			printf("└─┘ └─┘ └─┘ └─┘ \n");
			printf("개\n");
			break;
		case 3:
			printf("┌─┐ ┌─┐ ┌─┐ ┌─┐ \n");
			printf("│┼│ │ │ │ │ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │ │ │ │ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │ │ │ │ │ │ \n");
			printf("└─┘ └─┘ └─┘ └─┘ \n");
			printf("걸\n");
			break;

		case 4:
			printf("┌─┐ ┌─┐ ┌─┐ ┌─┐ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │ │ │ │ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("└─┘ └─┘ └─┘ └─┘ \n");
			printf("윷! 한번더!\n");
			break;
		case 5:
			printf("┌─┐ ┌─┐ ┌─┐ ┌─┐ \n");
			printf("│┼│ │┼│ │┼│ │┼│ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │┼│ │┼│ \n");
			printf("│ │ │ │ │ │ │ │ \n");
			printf("│┼│ │┼│ │┼│ │┼│ \n");
			printf("└─┘ └─┘ └─┘ └─┘ \n");
			printf("모~! 한번더!\n");
			break;
		}
		return yut;
	}
	void start() {
	
			printf("\n\n  ★ ☆ ");
			printf("┌─┐ ┌─┐ ┌─┐ ┌─┐ ★ ☆            ★                   ★           ☆\n");
			printf("     ☆ │┼│ │┼│ │┼│ │┼│★        ☆   ★          ☆          ★     ☆                     ★           ☆\n");
			printf("      ★│ │ │ │ │ │ │ │     ☆    ☆        ★             ☆             ★       ★\n");
			printf("   ☆   │┼│ │┼│ │┼│ │┼│                 ★        Korean boardgame Youtnoli!      ★  ☆      ☆      ★\n");
			printf("    ★  │ │ │ │ │ │ │ │        ★   ☆         ★         ☆   ★           ★           ☆            ☆\n");
			printf("  ☆    │┼│ │┼│ │┼│ │┼│    ★             ☆  ☆                 ★            ☆    ★            ☆\n");
			printf("      ★└─┘ └─┘ └─┘ └─┘           ★             ☆         ★       ★                      ☆\n");
			printf("  ☆               ★      ★           ☆           ★                     ☆            ★           ★ ");
			printf("\n\n                                          시작하려면 SpaceBar 키를 누르시오.");
		
	}
	/*void turn(int x) {
	}*/
	void gotoxy(int x, int y) {
		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	}
void CursorView() {
	CONSOLE_CURSOR_INFO cursorINfo = { 0 };
	cursorINfo.dwSize = 100;
	cursorINfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorINfo);
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
					x -= 2;
				break;
			case RIGHT:
				x += 2;
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
		else if (key == 32) {
			return;
		}
	}
	return;
}
void yutcursor(int* x, int y) {
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
		else if (key == 32) {
			return;
		}
	}
	return;
}
void visual(int yutbord[11][11],int red[4],int blue[4]) {
	gotoxy(0, 0);
	for (int i = 0; i < 11; i++) { // 윷놀이 판
		for (int j = 0; j < 11; j++) {
			switch (yutbord[i][j]) {
			case 0:printf("  "); break;
			case 1:printf("◎"); break;
			case 2:printf("｜"); break;
			case 3:printf("○"); break;
			case 4:printf("↘"); break;
			case 5:printf("↙"); break;
			case 6:printf("ㅡ"); break;
			case 7:printf(RED"●"RESET); break;
			case 8:printf(BLUE"●"RESET); break;
			}
		}
		printf("\n");
	}
	int j = 26;
	for (int i = 0; i < 4; i++) { // 현재 말 표현
		if (red[i] == 1) {
			gotoxy(j, 1); // 25,1 27,1 29,1 31,1
			Sleep(100);
			printf(RED"●"RESET);
			j += 2;
		}
	}
	j = 26;
	for (int i = 0; i < 4; i++) {
		if (blue[i] == 2) {
			gotoxy(j, 2);//25,2 27,2 29,2 31,2
			Sleep(100);
			printf(BLUE"●"RESET);
			j += 2;
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n");
}
void turncheck(int x) {
	CNT += x;
	if (CNT % 2 == 0) {
		printf("블루팀의 턴!");
	}
	else
		printf("레드팀의 턴!");
}
int enemycheck(int x, int y, int s) {
	//if ()
}
