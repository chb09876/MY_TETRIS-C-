#pragma once
#include <stdbool.h>

//�Ͻ�����
#define pause system("pause")

//�ܼ�ȭ�� �����
#define cls system("cls")

/*��Ʈ���� �� ��ũ��*/

//�ʵ� ����ü
struct location {
	bool shape;//0="  ", 1="��"
	bool control;//0=not,1=controled
};

struct location field[21][10];
struct location field_void = { 0,0 };
struct location field_controled = { 1,1 };
struct location field_fixed = { 1,0 };

struct pos {
	short x;
	short y;
};

struct pos block[4];

//����Ѱ�
bool move_R;//0=not,1=allow
bool move_L;//0=not,1=alllow
bool move_D;//0=not,1=allow
bool spawn_point;//0 or 1(normal)
char spawn_arr[1000];
int current_block;





