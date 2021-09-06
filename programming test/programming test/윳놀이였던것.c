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
void BD() {
	printf("����");
}
void Nak() {
	printf("��");
}
void Do() {
	printf("��");
}
void Gae() {
	printf("��");
}
void GUL() {
	printf("��");
}
void Yut() {
	printf("��");
}
void Mo() {
	printf("��");
}
int throw(){
	int n[4] = { 0 }; // ������ ��
	int N; // �� Ȯ��
	int result = 0;
	srand(time(NULL));
	while (1) {
	int key = _getch(); // �����̽��� �Է�
		if (key == 32) {
			for (int i = 0; i != 4; i++) { // �� ������
				n[i] = rand() % 2;
			}
			N = rand() % 20; // �� Ȯ�� 5%
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
		printf("������ ������ ������ ������\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� ������\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ ������ ������\n");
		break;
	case 0:
		printf("������         ������\n");
		printf("�� ��         �� ��\n");
		printf("�� ��         �� ������ \n");
		printf("�� ���������������������� ������\n");
		printf("�������������������������� ��\n");
		printf("            ������\n");
		printf("   ���������������������� \n");
		printf("   ������������������ �� \n");
		printf("           �� �� \n");
		printf("           ������ \n");
		break;
	case 1:
		printf("������ ������ ������ ������\n");
		printf("������ �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ �� �� �� �� �� ��\n");
		printf("������ ������ ������ ������\n");
		break;
	case 2:
		printf("������ ������ ������ ������\n");
		printf("������ ������ �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ �� �� �� ��\n");
		printf("������ ������ ������ ������\n");
		break;
	case 3:
		printf("������ ������ ������ ������\n");
		printf("������ ������ ������ �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ ������ �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ ������ �� ��\n");
		printf("������ ������ ������ ������\n");
		break;

	case 4:
		printf("������ ������ ������ ������\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ ������ ������\n");
		break;
	case 5:
		printf("������ ������ ������ ������\n");
		printf("������ ������ ������ ������\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ ������ ������\n");
		printf("�� �� �� �� �� �� �� ��\n");
		printf("������ ������ ������ ������\n");
		printf("������ ������ ������ ������\n");
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
	} // ����ȭ�� �Ѿ�� �ڵ�
	while (1) {
		for (int i = 0; i < 11; i++) { // ������ ��
			for (int j = 0; j < 11; j++) {
				switch (yutbord[i][j]) {
				case 0:printf("  "); break;
				case 1:printf("��"); break;
				case 2:printf("��"); break;
				case 3:printf("��"); break;
				case 4:printf("��"); break;
				case 5:printf("��"); break;
				case 7:printf("��"); break;
				}
			}
			printf("\n");
		}
		printf("%d��° ��!\nSpaceBar�� ������ ���� ��������!\n", CNT); // �� �˷���

		int n = throw(); // �� ������, ������ ���� �� ǥ��
		look(n);
		j = 25;
		for (int i = 0; i != 8; i++) { // ���� �� ǥ��
			if (i < 4) {
				if (red[i] == 1) {
					gotoxy(j, 1); // 25,1 27,1 29,1 31,1
					Sleep(100);
					printf(RED"�� ");
					j += 2;
				}
			}
			else {
				if (blue[i - 4] == 2) {
					gotoxy(j - 8, 2);//25,2 27,2 29,2 31,2
					Sleep(100);
					printf(BLUE"�� "RESET);
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
			printf("������ ����");
		else if ((CX == 25 && CY == 2) || (CX == 27 && CY == 2) || (CX == 29 && CY == 2) || (CX == 31 && CY == 2))
			printf("����� ����");
		gotoxy(0, 20);
		printf("\n\n���� �Ѿ�ðڽ��ϱ�?");
		while (1) {
			int key = _getch(); // �����̽��� �Է�
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