#pragma once

//���θ޴�
void mainmenu();

//ȭ�� Ŭ����
void clear();

//Ŀ�� �̵�
void gotoxy(short x, short y);

/*��Ʈ���� �����Լ� ����*/

//��Ʈ����
void Tetris();

//�й����� Ȯ��
void islose(struct location f[][10]);

//ȭ�� ���
void show_T(struct location f[][10]);