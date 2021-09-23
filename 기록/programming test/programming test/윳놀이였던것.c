#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
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
void turn(int n) {
	/*if (n % 2 == 0) {

	}*/
}
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
void BD() {
	printf("빽도");
}
void Nak() {
	printf("낙");
}
void Do() {
	printf("도");
}
void Gae() {
	printf("개");
}
void GUL() {
	printf("걸");
}
void Yut() {
	printf("윷");
}
void Mo() {
	printf("모");
}
int throw(){
	int n[4] = { 0 }; // 윷놀이 말
	int N; // 낙 확률
	int result = 0;
	srand(time(NULL));
	while (1) {
	int key = _getch(); // 스페이스바 입력
		if (key == 32) {
			for (int i = 0; i != 4; i++) { // 말 던지기
				n[i] = rand() % 2;
			}
			N = rand() % 20; // 낙 확률 5%
			//printf("%d %d %d %d %d", n[0], n[1], n[2], n[3], N);
			if (N == 0) {

				result = 0;
			}
			else if (N != 0)
			{
				if (n[0] + n[1] + n[2] + n[3] == 0) {

					result = 4;
				}
				else if (n[0] + n[1] + n[2] + n[3] == 1) {
					if (n[0] == 1) {

						result = -1;
					}
					else
					{
						result = 1;
					}
				}
				else if (n[0] + n[1] + n[2] + n[3] == 2) {

					result = 2;
				}
				else if (n[0] + n[1] + n[2] + n[3] == 3) {

					result = 3;
				}
				else if (n[0] + n[1] + n[2] + n[3] == 4) {

					result = 4;
				}
			}
			break;
		}
		else
			continue;
	}
	return result;
}
void look(int n) {
	switch (n) {
	case -1:
		printf("┌─┐ ┌─┐ ┌─┐ ┌─┐\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │┼│\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("└─┘ └─┘ └─┘ └─┘\n");
		break;
	case 0:
		printf("┌─┐         ┌─┐\n");
		printf("│ │         │ │\n");
		printf("│ │         │ └─┐ \n");
		printf("│ └─────────┤ ┌─┘\n");
		printf("└───────────┤ │\n");
		printf("            └─┘\n");
		printf("   ┌─────────┐ \n");
		printf("   └───────┐ │ \n");
		printf("           │ │ \n");
		printf("           └─┘ \n");
		break;
	case 1:
		printf("┌─┐ ┌─┐ ┌─┐ ┌─┐\n");
		printf("│┼│ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │ │ │ │ │ │\n");
		printf("└─┘ └─┘ └─┘ └─┘\n");
		break;
	case 2:
		printf("┌─┐ ┌─┐ ┌─┐ ┌─┐\n");
		printf("│┼│ │┼│ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │┼│ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │┼│ │ │ │ │\n");
		printf("└─┘ └─┘ └─┘ └─┘\n");
		break;
	case 3:
		printf("┌─┐ ┌─┐ ┌─┐ ┌─┐\n");
		printf("│┼│ │┼│ │┼│ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │┼│ │┼│ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │┼│ │┼│ │ │\n");
		printf("└─┘ └─┘ └─┘ └─┘\n");
		break;

	case 4:
		printf("┌─┐ ┌─┐ ┌─┐ ┌─┐\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("└─┘ └─┘ └─┘ └─┘\n");
		break;
	case 5:
		printf("┌─┐ ┌─┐ ┌─┐ ┌─┐\n");
		printf("│┼│ │┼│ │┼│ │┼│\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │┼│ │┼│ │┼│\n");
		printf("│ │ │ │ │ │ │ │\n");
		printf("│┼│ │┼│ │┼│ │┼│\n");
		printf("└─┘ └─┘ └─┘ └─┘\n");
		break;
	default:
		break;
	}
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
			return;
		}
	}
	return;
}
int main() {
	CursorView();
	CONSOLE_SCREEN_BUFFER_INFO presentCur;
	int key = 0;
	int n = 0;
	int CNT = 0;
	int red[4] = { 1,1,1,1 };
	int blue[4] = { 2,2,2,2 };
	int j = 25;
	int yutbord[11][11] = { {1,7,3,7,3,7,3,7,3,7,1},{2,4,0,0,0,0,0,0,0,5,2},{3,0,3,0,0,0,0,0,3,0,3},{2,0,0,4,0,0,0,5,0,0,2},{3,0,0,0,3,0,3,0,0,0,3},{2,0,0,0,0,1,0,0,0,0,2},{3,0,0,0,5,0,4,0,0,0,3},{2,0,0,3,0,0,0,3,0,0,2},{3,0,5,0,0,0,0,0,4,0,3},{2,3,0,0,0,0,0,0,0,3,2}, {1,7,3,7,3,7,3,7,3,7,1} };
	start();
	while (1)
	{
		key = _getch();
		if (key == 32) {
			system("cls");
			break;
		}
		else
			continue;
	} // 시작화면 넘어가는 코드
	while (1) {
		for (int i = 0; i < 11; i++) { // 윷놀이 판
			for (int j = 0; j < 11; j++) {
				switch (yutbord[i][j]) {
				case 0:printf("  "); break;
				case 1:printf("◎"); break;
				case 2:printf("｜"); break;
				case 3:printf("○"); break;
				case 4:printf("↘"); break;
				case 5:printf("↙"); break;
				case 7:printf("ㅡ"); break;
				}
			}
			printf("\n");
		}
		printf("%d번째 턴!\nSpaceBar를 눌러서 윷을 던지세요!\n", CNT); // 턴 알려줌

		int n = throw(); // 윷 던지기, 던져서 나온 윷 표현
		look(n);
		j = 25;
		for (int i = 0; i != 8; i++) { // 현재 말 표현
			if (i < 4) {
				if (red[i] == 1) {
					gotoxy(j, 1); // 25,1 27,1 29,1 31,1
					Sleep(100);
					printf(RED"● ");
					j += 2;
				}
			}
			else {
				if (blue[i - 4] == 2) {
					gotoxy(j - 8, 2);//25,2 27,2 29,2 31,2
					Sleep(100);
					printf(BLUE"● "RESET);
					j += 2;
				}
			}

		}
		printf("\n");

		/*system("cls");*/
	//n = throw();
	//look(n);
		/*switch (n) {
		case -1:
			BD();
			break;
		case 0:
			Nak();
			break;
		case 1:
			Do();
			break;
		case 2:
			Gae();
			break;
		case 3:
			GUL();
			break;
		case 4:
			Yut();
			break;
		case 5:
			Mo();
			break;
		default:
			break;
		}*/
		CNT++;
		turn(CNT);
		Cursor(20, 10);
		spot;
		if ((CX == 25 && CY == 1) || (CX == 27 && CY == 1) || (CX == 29 && CY == 1) || (CX == 31 && CY == 1))
			printf("레드팀 선택");
		else if ((CX == 25 && CY == 2) || (CX == 27 && CY == 2) || (CX == 29 && CY == 2) || (CX == 31 && CY == 2))
			printf("블루팀 선택");
		gotoxy(0, 20);
		printf("\n\n턴을 넘어가시겠습니까?");
		while (1) {
			int key = _getch(); // 스페이스바 입력
			if (key != 32) {
				continue;
			}
			else if (key == 32) {
				system("cls");
				break;

			}
		}
	}
}