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
void victory();
void Backdo(int x, int y);
int CNT = 1;
void turncheck(int x);//팀 구별하는거
void Cmove1(int x, int y);
void Cmove2(int x, int y);
void gotoxy();
void CursorView();
void move(int x, int y);
//void fin(int x int y);
void visual(int yutbord[11][11], int red[4], int blue[4]);
int yutbord[11][11] = { {3,6,3,6,3,6,3,6,3,6,3},
						{2,4,0,0,0,0,0,0,0,5,2},
						{3,0,3,0,0,0,0,0,3,0,3},
						{2,0,0,4,0,0,0,5,0,0,2},
						{3,0,0,0,3,0,3,0,0,0,3},
						{2,0,0,0,0,3,0,0,0,0,2},
						{3,0,0,0,5,0,4,0,0,0,3},
						{2,0,0,3,0,0,0,3,0,0,2},
						{3,0,5,0,0,0,0,0,4,0,3},
						{2,3,0,0,0,0,0,0,0,3,2},
						{3,6,3,6,3,6,3,6,3,6,3} };
int red[4] = { 1,1,1,1 };
int blue[4] = { 2,2,2,2 };
int check(int x, int y, int s);
int moveselect(int x);
int main() {
	CursorView();
	CONSOLE_SCREEN_BUFFER_INFO presentCur;
	int yut;
	int n = 0;
	int fx = 0, fy = 0, fsr = 3, fsb = 3;
	int c = 0;
	int mal = 0;
	start();
	while (1) {
		if (_getch() == 32) {
			system("cls");
			break;
		}
	}// 시작화면 넘어가는 코드
	visual(yutbord, red, blue);
	while (1) {
		printf("%d번째 턴!\nSpaceBar를 눌러서 윷을 던지세요!\n", CNT); // 턴 알려줌
		yut = throwyut();
		int temp = yut;
		// 현재 말 표현

	   /*system("cls");*/
   //n = throw();
   //look(n);

		while (1) {
			Cursor(20, 10);
			spot;
			fx = CX; fy = CY;//이게 신기한게 y값을 행에넣고 x/2값을 열에넣으면 배열상에 그 뭐시기한게 되더라고
			if (yutbord[fy][fx / 2] == 7 && CNT % 2 == 1) {//판위에 있는 말들 움직이는거
				/*if (yut == -1) {
					spot;
					Backdo(CX, CY);
				}*/
				//else {
				spot;
				if (CX == 10 && CY == 5) {
					gotoxy(25, 10);
					printf("고르세요 1or2:");
					scanf_s("%d", &c);
					gotoxy(10, 5);
					switch (c) {
					case 1: spot;  CX -= 4; CY += 2;
						gotoxy(CX, CY); yut--; break;
					case 2: spot; CX += 4; CY += 2;  gotoxy(CX, CY); yut--; break;
					}
				}
				spot;
				if (CX == 20 && CY == 0) {
					gotoxy(25, 10);
					printf("고르세요 1or2:");
					scanf_s("%d", &c);
					gotoxy(20, 0);
					switch (c) {
					case 1: break;
					case 2: spot;  CX -= 4; CY += 2;
						gotoxy(CX, CY); yut--; break;
					}
				}
				spot;
				if (CX == 0 && CY == 0) {
					gotoxy(25, 10);
					printf("고르세요 1or2:");
					scanf_s("%d", &c);
					gotoxy(0, 0);
					switch (c) {
					case 1: break;
					case 2: spot;  CX += 4; CY += 2; gotoxy(CX, CY); yut--; break;
					}
				}
				for (int i = 0; i != yut; yut--) {
					spot;
					gotoxy(CX, CY);
					spot;
					move(CX, CY);
					int o;
					spot;
					int x = CX, y = CY;
					Cmove2(x, y);
					spot;
					if (x != CX || y != CY) {
						o = 2;
					}
					gotoxy(CX, CY);
					spot;
					if (CX == 10 && CY == 5) {
						if (yut == 1) {
							break;
						}
						if (o == 2) {
							spot;  CX += 4; CY += 2; gotoxy(CX, CY); break;
						}
						if (yut > 1)
							yut--;
						continue;
					}
					spot;
					x = CX, y = CY;
					Cmove1(x, y);
					spot;
					if (x != CX || y != CY) {
						o = 1;
					}
					gotoxy(CX, CY);
					spot;
					if (CX == 10 && CY == 5) {
						if (yut == 1) {
							break;
						}
						if (o == 1) {
							spot;  CX -= 4; CY += 2; gotoxy(CX, CY);
							break;
						}
						if (yut > 1)
							yut--;
					}
					//}
				}
				yutbord[fy][fx / 2] = 3;//말이 움직이고 남은곳에 원래 있던값으로 ㄱㄱ
				spot;//현재위치 재껴서
				/*
				함수 넣을곳
				*/
				yutbord[CY][CX / 2] = 7;//그리고 말을 선택한 위치에 놓는다 
				//상대말 잡는거는 여따넣을거임 그리고 모,윷등에관한 예외도 여기서처리
				visual(yutbord, red, blue);//화면 갱신
				break;
			}
			else if (yutbord[CY][CX / 2] == 8 && CNT % 2 == 0) {
				/*if (yut == -1) {
					spot;
					Backdo(CX, CY);
				}*/
				//else {
				spot;
				if (CX == 10 && CY == 5) {
					gotoxy(25, 10);
					printf("고르세요 1or2:");
					scanf_s("%d", &c);
					gotoxy(10, 5);
					switch (c) {
					case 1: spot;  CX -= 4; CY += 2; gotoxy(CX, CY); yut--; break;
					case 2: spot; CX += 4; CY += 2; gotoxy(CX, CY); yut--; break;
					}
				}
				spot;
				if (CX == 20 && CY == 0) {
					gotoxy(25, 10);
					printf("고르세요 1or2:");
					scanf_s("%d", &c);
					gotoxy(20, 0);
					switch (c) {
					case 1: break;
					case 2: spot;  CX -= 4; CY += 2; gotoxy(CX, CY); yut--; break;
					}
				}
				spot;
				if (CX == 0 && CY == 0) {
					gotoxy(25, 10);
					printf("고르세요 1or2:");
					scanf_s("%d", &c);
					gotoxy(0, 0);
					switch (c) {
					case 1: break;
					case 2: spot;  CX += 4; CY += 2; gotoxy(CX, CY); yut--; break;
					}
				}

				for (int i = 0; i != yut; yut--) {
					spot;
					move(CX, CY);
					spot;
					gotoxy(CX, CY);
					int o;
					spot;
					int x = CX, y = CY;
					Cmove1(x, y);
					spot;
					if (x != CX || y != CY) {
						o = 1;
					}
					gotoxy(CX, CY);
					spot;
					if (CX == 10 && CY == 5) {
						if (yut == 1) {
							break;
						}
						if (o == 1) {
							spot; CX -= 4; CY += 2;  gotoxy(CX, CY); break;
						}
						if (yut > 1)
							yut--;
						continue;
					}
					spot;
					x = CX, y = CY;
					Cmove2(CX, CY);
					gotoxy(CX, CY);
					spot;
					if (x != CX || y != CY) {
						o = 2;
					}
					spot;
					if (CX == 10 && CY == 5) {
						if (yut == 1) {
							yut--;
							break;
						}
						if (o) {
							spot; CX += 4; CY += 2; gotoxy(CX, CY); break;
						}
						if (yut > 1)
							yut--;
					}
				}
				//}
				yutbord[fy][fx / 2] = 3;
				spot;
				/*
				함수 넣을곳
				*/
				yutbord[CY][CX / 2] = 8;
				visual(yutbord, red, blue);
				break;
			}
			else if (((CX == 26 && CY == 1) || (CX == 28 && CY == 1) || (CX == 30 && CY == 1) || (CX == 32 && CY == 1)) && CNT % 2 == 1) {
				if (yut == -1) {
					spot;
					printf("아 ㅋㅋ 되겠냐고");
				}
				else {
					yutbord[10][10] = 7;//여긴 맨처음에 말있던데에서 판에 올리는거 알지?
					for (int i = 0; i < 4; i++) {
						if (red[i] == 1) {//음..대충 말남은 개수 출력하는거
							red[i] = 0;//한바퀴 돈 말출력도 여기서하는게 이상적
							break;
						}
					}
					system("cls");
					visual(yutbord, red, blue);
					gotoxy(20, 10);
					for (int i = 0; i != yut; yut--) {
						spot;
						gotoxy(CX, (CY -= 2));
						spot;
						gotoxy(CX, CY);
					}
				}
				spot;
				/*
				함수 넣을곳
				*/
				yutbord[CY][CX / 2] = 7;//이부분은 맨처음 판에 온 말이 움직이는건데 솔직히 없어도 될거같음 근데 이거 없앨라면 저위에있는걸 
				yutbord[10][10] = 3;//함수로 빼야되서 귀찮음
				visual(yutbord, red, blue);
				break;
			}
			else if (((CX == 26 && CY == 2) || (CX == 28 && CY == 2) || (CX == 30 && CY == 2) || (CX == 32 && CY == 2)) && CNT % 2 == 0) {
				if (yut == -1) {
					spot;
					printf("아 ㅋㅋ 되겠냐고");
				}
				else {
					yutbord[10][10] = 8;
					for (int i = 0; i < 4; i++) {
						if (blue[i] == 2) {
							blue[i] = 0;
							break;
						}
					}
					system("cls");
					visual(yutbord, red, blue);
					gotoxy(20, 10);
					for (int i = 0; i != yut; yut--) {
						spot;
						gotoxy(CX, (CY -= 2));
						spot;
						gotoxy(CX, CY);
					}
				}
				spot;
				/*
				함수 넣을곳
				*/
				yutbord[CY][CX / 2] = 8;
				yutbord[10][10] = 3;
				visual(yutbord, red, blue);
				break;
			}
			else {
				gotoxy(26, 3);
				printf("잘못된선택");//이건 잘못선택한거 그리고여기에 자기턴아닐떄 남의말건드린것도 넣어야하긴함
				continue;
			}

		}

		while (1) {
			if (_getch() == 32) {// 스페이스바 입력
				system("cls");
				visual(yutbord, red, blue);
				break;//솔직히 이쪽은 쓸모없는듯
			}
			else if (_getch() != 32) {
				continue;
			}
		}
		if (temp == 4 || temp == 5) {
			turncheck(0);//여기가 윳,모 나오면 턴 카운트하는걸 없애는거긴한데 저위쪽에 새로만들면 거기로 갈예정
		}
		else
			turncheck(1);
	}

}

int throwyut() {
	int n[4] = { 0 }; // 윷
	int result = 0;// 윷을 던진결과
	srand(time(NULL));
	int yut = 0;
	// 스페이스바 입력
	if (_getch() == 32) {
		for (int i = 0; i != 4; i++) // 윷 던지기
			n[i] = rand() % 2;
		yut = n[0] + n[1] + n[2] + n[3];

		switch (yut) {
		case 0:result = 5; break;
		case 1:
			//if (n[0] == 1)
			//	result = -1;
			//else
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
	return result;
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
void visual(int yutbord[11][11], int red[4], int blue[4]) {
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
			case 9:printf(RED"▲"RESET); break;//2개업은거 참고로 아직안만듬
			case 10:printf(BLUE"▲"RESET); break;
			case 11:printf(RED"■"RESET); break;//3개업은거
			case 12:printf(BLUE"■"RESET); break;
			case 13:printf(RED"★"RESET); break;//뭔지알지?
			case 14:printf(BLUE"★"RESET); break;
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
	printf("\n\n\n\n\n\n\n\n\n\n\n");//솔직히 이거맘에 안드는데 귀찮음
}
void turncheck(int x) {
	CNT += x;
	if (CNT % 2 == 0) {
		printf("블루팀의 턴!");//여기가 일단 기본적인 턴 계산 이것도 좀더해야함
	}
	else
		printf("레드팀의 턴!");
}
int check(int x, int y, char colors, int mymal) {//이게아마 적잡아 먹는거 할건데 생각해보니 윷,모도 넣을라면 이름 바꿔야하네
	if (colors == "red") {
		if (yutbord[y][x / 2] == 8) {
			for (int i = 0; i < 4; i++) {
				if (blue[i] == 0) {
					blue[i] = 2;

					break;
				}
			}
			return 7;
		}
		else if (yutbord[y][x / 2] == 7) {
			for (int i = 7; i < 15; i++) {

			}
		}
	}
}
int moveselect(int x, int y, int z) {//이게 그 대각선이랑 직선 분기점이 될예정임

}
//void fin(int x int y) {////이거끝내는거임

//}
void move(int x, int y) {
	if (x == 20 && y != 0) {
		y -= 2;
		gotoxy(x, y);
	}
	else if (y == 0 && x != 0) {
		x -= 4;
		gotoxy(x, y);
	}
	else if (x == 0 && y != 10) {
		y += 2;
		gotoxy(x, y);
	}
	else if (y == 10) {
		/* if (x == 20) {
			victory();
		} */
		x += 4;
		gotoxy(x, y);
	}
	else {

	}
}
void Cmove1(int x, int y) {
	if ((x == 16 && y == 2) || (x == 12 && y == 4) || (x == 6 && y == 7) || (x == 2 && y == 9)) {
		if ((x == 12 && y == 4) || (x == 2 && y == 9)) {
			x -= 2;
			y += 1;
			gotoxy(x, y);
		}
		else {
			x -= 4;
			y += 2;
			gotoxy(x, y);
		}
	}

}
void Cmove2(int x, int y) {
	if ((x == 4 && y == 2) || (x == 8 && y == 4) || (x == 14 && y == 7) || (x == 18 && y == 9)) {
		if ((x == 8 && y == 4) || (x == 18 && y == 9)) {
			x += 2;
			y += 1;
			gotoxy(x, y);
		}
		else {
			x += 4;
			y += 2;
			gotoxy(x, y);
		}
	}
}
void Backdo(int x, int y) {
	int c;
	if (x == 20 && (y != 0 && y != 10)) {
		y += 2;
		gotoxy(x, y);
	}
	else if (y == 0 && (x != 0 && x != 20)) {
		x += 4;
		gotoxy(x, y);
	}
	else if (x == 0 && (y != 10 && y != 0)) {
		y -= 2;
		gotoxy(x, y);
	}
	else if (y == 10 && x != 0) {
		/* if (x == 20) {
			victory();
		} */
		x -= 4;
		gotoxy(x, y);
	}
	else if ((x == 16 && y == 2) || (x == 12 && y == 4) || (x == 6 && y == 7) || (x == 2 && y == 9)) {
		x += 4;
		y -= 2;
		gotoxy(x, y);
	}
	else if ((x == 4 && y == 2) || (x == 8 && y == 4) || (x == 14 && y == 7) || (x == 18 && y == 9)) {
		x -= 4;
		y -= 2;
		gotoxy(x, y);

	}
	else if (x == 10 && y == 5) {
		gotoxy(25, 10);
		printf("고르세요 1or2:");
		scanf_s("%d", &c);
		gotoxy(10, 5);
		switch (c) {
		case 1: x += 2; y -= 1; gotoxy(x, y); break;
		case 2: x -= 2; y -= 1; gotoxy(x, y); break;
		}
	}
	else if (x == 20 && y == 10) {
		gotoxy(25, 10);
		printf("고르세요 1or2:");
		scanf_s("%d", &c);
		gotoxy(20, 10);
		switch (c) {
		case 1: x -= 4; gotoxy(x, y); break;
		case 2: x -= 2; y -= 1; gotoxy(x, y); break;
		}
	}
	else if (x == 0 && y == 10) {
		gotoxy(25, 10);
		printf("고르세요 1or2:");
		scanf_s("%d", &c);
		gotoxy(0, 10);
		switch (c) {
		case 1: y -= 2; gotoxy(x, y); break;
		case 2: x += 2; y -= 1; gotoxy(x, y); break;
		}
	}
}
