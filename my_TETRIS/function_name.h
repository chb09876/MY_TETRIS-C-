#pragma once
#include <stdbool.h>
//���θ޴�
void mainmenu();

//Ŀ�� �̵�
void gotoxy(short x, short y);

void debug();

/*��Ʈ���� �����Լ� ����*/

//��Ʈ����
void Tetris();

//���� ����
void init_update();

//���� ����
void info_update();

//�й����� Ȯ��
void islose();

//ȭ�� ���
void show_T();

//�߷�

void loc_update();

void moveright();

void moveleft();

void movedown();

void moveup();

void turnR();

void fix();

//�� ����
void spawn_block(int num);