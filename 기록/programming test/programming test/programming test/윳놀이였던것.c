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
void turncheck(int x);//�� �����ϴ°�
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
	}// ����ȭ�� �Ѿ�� �ڵ�
	visual(yutbord, red, blue);
	while (1) {
		printf("%d��° ��!\nSpaceBar�� ������ ���� ��������!\n", CNT); // �� �˷���
		yut = throwyut();
		int temp = yut;
		// ���� �� ǥ��

	   /*system("cls");*/
   //n = throw();
   //look(n);

		while (1) {
			Cursor(20, 10);
			spot;
			fx = CX; fy = CY;//�̰� �ű��Ѱ� y���� �࿡�ְ� x/2���� ���������� �迭�� �� ���ñ��Ѱ� �Ǵ����
			if (yutbord[fy][fx / 2] == 7 && CNT % 2 == 1) {//������ �ִ� ���� �����̴°�
				/*if (yut == -1) {
					spot;
					Backdo(CX, CY);
				}*/
				//else {
				spot;
				if (CX == 10 && CY == 5) {
					gotoxy(25, 10);
					printf("������ 1or2:");
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
					printf("������ 1or2:");
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
					printf("������ 1or2:");
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
				yutbord[fy][fx / 2] = 3;//���� �����̰� �������� ���� �ִ������� ����
				spot;//������ġ �粸��
				/*
				�Լ� ������
				*/
				yutbord[CY][CX / 2] = 7;//�׸��� ���� ������ ��ġ�� ���´� 
				//��븻 ��°Ŵ� ������������ �׸��� ��,������� ���ܵ� ���⼭ó��
				visual(yutbord, red, blue);//ȭ�� ����
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
					printf("������ 1or2:");
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
					printf("������ 1or2:");
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
					printf("������ 1or2:");
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
				�Լ� ������
				*/
				yutbord[CY][CX / 2] = 8;
				visual(yutbord, red, blue);
				break;
			}
			else if (((CX == 26 && CY == 1) || (CX == 28 && CY == 1) || (CX == 30 && CY == 1) || (CX == 32 && CY == 1)) && CNT % 2 == 1) {
				if (yut == -1) {
					spot;
					printf("�� ���� �ǰڳİ�");
				}
				else {
					yutbord[10][10] = 7;//���� ��ó���� ���ִ������� �ǿ� �ø��°� ����?
					for (int i = 0; i < 4; i++) {
						if (red[i] == 1) {//��..���� ������ ���� ����ϴ°�
							red[i] = 0;//�ѹ��� �� ����µ� ���⼭�ϴ°� �̻���
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
				�Լ� ������
				*/
				yutbord[CY][CX / 2] = 7;//�̺κ��� ��ó�� �ǿ� �� ���� �����̴°ǵ� ������ ��� �ɰŰ��� �ٵ� �̰� ���ٶ�� �������ִ°� 
				yutbord[10][10] = 3;//�Լ��� ���ߵǼ� ������
				visual(yutbord, red, blue);
				break;
			}
			else if (((CX == 26 && CY == 2) || (CX == 28 && CY == 2) || (CX == 30 && CY == 2) || (CX == 32 && CY == 2)) && CNT % 2 == 0) {
				if (yut == -1) {
					spot;
					printf("�� ���� �ǰڳİ�");
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
				�Լ� ������
				*/
				yutbord[CY][CX / 2] = 8;
				yutbord[10][10] = 3;
				visual(yutbord, red, blue);
				break;
			}
			else {
				gotoxy(26, 3);
				printf("�߸��ȼ���");//�̰� �߸������Ѱ� �׸����⿡ �ڱ��Ͼƴҋ� ���Ǹ��ǵ帰�͵� �־���ϱ���
				continue;
			}

		}

		while (1) {
			if (_getch() == 32) {// �����̽��� �Է�
				system("cls");
				visual(yutbord, red, blue);
				break;//������ ������ ������µ�
			}
			else if (_getch() != 32) {
				continue;
			}
		}
		if (temp == 4 || temp == 5) {
			turncheck(0);//���Ⱑ ��,�� ������ �� ī��Ʈ�ϴ°� ���ִ°ű��ѵ� �����ʿ� ���θ���� �ű�� ������
		}
		else
			turncheck(1);
	}

}

int throwyut() {
	int n[4] = { 0 }; // ��
	int result = 0;// ���� �������
	srand(time(NULL));
	int yut = 0;
	// �����̽��� �Է�
	if (_getch() == 32) {
		for (int i = 0; i != 4; i++) // �� ������
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
		printf("������ ������ ������ ������ \n");
		printf("������ ������ ������ �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ ������ �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("����!\n");
		break;
	case 1:
		printf("������ ������ ������ ������ \n");
		printf("������ ������ ������ �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ ������ �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ ������ �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("��\n");

		break;
	case 2:
		printf("������ ������ ������ ������ \n");
		printf("������ ������ �� �� �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ �� �� �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ �� �� �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("��\n");
		break;
	case 3:
		printf("������ ������ ������ ������ \n");
		printf("������ �� �� �� �� �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ �� �� �� �� �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ �� �� �� �� �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("��\n");
		break;

	case 4:
		printf("������ ������ ������ ������ \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ �� �� �� �� �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("��! �ѹ���!\n");
		break;
	case 5:
		printf("������ ������ ������ ������ \n");
		printf("������ ������ ������ ������ \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("�� �� �� �� �� �� �� �� \n");
		printf("������ ������ ������ ������ \n");
		printf("������ ������ ������ ������ \n");
		printf("��~! �ѹ���!\n");
		break;
	}
	return result;
}
void start() {

	printf("\n\n  �� �� ");
	printf("������ ������ ������ ������ �� ��            ��                   ��           ��\n");
	printf("     �� ������ ������ ������ ��������        ��   ��          ��          ��     ��                     ��           ��\n");
	printf("      �ڦ� �� �� �� �� �� �� ��     ��    ��        ��             ��             ��       ��\n");
	printf("   ��   ������ ������ ������ ������                 ��        Korean boardgame Youtnoli!      ��  ��      ��      ��\n");
	printf("    ��  �� �� �� �� �� �� �� ��        ��   ��         ��         ��   ��           ��           ��            ��\n");
	printf("  ��    ������ ������ ������ ������    ��             ��  ��                 ��            ��    ��            ��\n");
	printf("      �ڦ����� ������ ������ ������           ��             ��         ��       ��                      ��\n");
	printf("  ��               ��      ��           ��           ��                     ��            ��           �� ");
	printf("\n\n                                          �����Ϸ��� SpaceBar Ű�� �����ÿ�.");

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
	for (int i = 0; i < 11; i++) { // ������ ��
		for (int j = 0; j < 11; j++) {
			switch (yutbord[i][j]) {
			case 0:printf("  "); break;
			case 1:printf("��"); break;
			case 2:printf("��"); break;
			case 3:printf("��"); break;
			case 4:printf("��"); break;
			case 5:printf("��"); break;
			case 6:printf("��"); break;
			case 7:printf(RED"��"RESET); break;
			case 8:printf(BLUE"��"RESET); break;
			case 9:printf(RED"��"RESET); break;//2�������� ����� �����ȸ���
			case 10:printf(BLUE"��"RESET); break;
			case 11:printf(RED"��"RESET); break;//3��������
			case 12:printf(BLUE"��"RESET); break;
			case 13:printf(RED"��"RESET); break;//��������?
			case 14:printf(BLUE"��"RESET); break;
			}
		}
		printf("\n");
	}
	int j = 26;
	for (int i = 0; i < 4; i++) { // ���� �� ǥ��
		if (red[i] == 1) {
			gotoxy(j, 1); // 25,1 27,1 29,1 31,1
			Sleep(100);
			printf(RED"��"RESET);
			j += 2;
		}
	}
	j = 26;
	for (int i = 0; i < 4; i++) {
		if (blue[i] == 2) {
			gotoxy(j, 2);//25,2 27,2 29,2 31,2
			Sleep(100);
			printf(BLUE"��"RESET);
			j += 2;
		}
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n");//������ �̰Ÿ��� �ȵ�µ� ������
}
void turncheck(int x) {
	CNT += x;
	if (CNT % 2 == 0) {
		printf("������� ��!");//���Ⱑ �ϴ� �⺻���� �� ��� �̰͵� �����ؾ���
	}
	else
		printf("�������� ��!");
}
int check(int x, int y, char colors, int mymal) {//�̰ԾƸ� ����� �Դ°� �Ұǵ� �����غ��� ��,�� ������� �̸� �ٲ���ϳ�
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
int moveselect(int x, int y, int z) {//�̰� �� �밢���̶� ���� �б����� �ɿ�����

}
//void fin(int x int y) {////�̰ų����°���

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
		printf("������ 1or2:");
		scanf_s("%d", &c);
		gotoxy(10, 5);
		switch (c) {
		case 1: x += 2; y -= 1; gotoxy(x, y); break;
		case 2: x -= 2; y -= 1; gotoxy(x, y); break;
		}
	}
	else if (x == 20 && y == 10) {
		gotoxy(25, 10);
		printf("������ 1or2:");
		scanf_s("%d", &c);
		gotoxy(20, 10);
		switch (c) {
		case 1: x -= 4; gotoxy(x, y); break;
		case 2: x -= 2; y -= 1; gotoxy(x, y); break;
		}
	}
	else if (x == 0 && y == 10) {
		gotoxy(25, 10);
		printf("������ 1or2:");
		scanf_s("%d", &c);
		gotoxy(0, 10);
		switch (c) {
		case 1: y -= 2; gotoxy(x, y); break;
		case 2: x += 2; y -= 1; gotoxy(x, y); break;
		}
	}
}
