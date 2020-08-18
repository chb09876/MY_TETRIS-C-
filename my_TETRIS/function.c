#include "function_name.h"
#include "component.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/*��ƿ�Լ�����*/

//���θ޴�
void mainmenu() {
	while (1) {
		printf("��带 �����ϼ���\n");
		printf("1. TETRIS\n");
		printf("[Esc] to EXIT\n");
		switch (_getch()) {
		case '1':
			Tetris();
			break;
		case 27:
			return 0;
		}
	}
}

//ȭ�� Ŭ����
void clear() {
	system("cls");
}

//Ŀ�� �̵�
void gotoxy(short x, short y) {
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

/*��Ʈ�����Լ�����*/

//��Ʈ����
void Tetris() {
	cls;
	struct location field[21][10];
	for (int i = 1; i < 21; i++) {
		for (int ii = 0; ii < 10; ii++) {
			field[i][ii].shape = 1;
		}
	}
	show_T(field);
	field[0][4].shape = 1;
	islose(field);
	pause;
}

//�й����� üũ
void islose(struct location f[][10]) {
	for (int i = 0; i < 10; i++) {
		if (f[0][i].shape == 1) {
			cls;
			printf("you lose");
			pause;
			return mainmenu;
		}
	}
}

//����Լ�
void show_T(struct location (*f)[10]) {
	for (int i = 1; i < 21; i++) {
		for (int ii = 0; ii < 10; ii++) {
			if (f[i][ii].shape == 1) {
				printf("��");
			}
			else if (f[i][ii].shape == 0) {
				printf("  ");
			}
		}
		printf("\n");
	}
	gotoxy(0, 0);
}