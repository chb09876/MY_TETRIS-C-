#pragma once
#include <stdbool.h>

//일시정지
#define pause system("pause")

//콘솔화면 지우기
#define cls system("cls")

/*테트리스 블럭 매크로*/

//필드 구조체
struct location {
	bool shape;//0="  ", 1="■"
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

//잡다한것
bool move_R;//0=not,1=allow
bool move_L;//0=not,1=alllow
bool move_D;//0=not,1=allow
bool spawn_point;//0 or 1(normal)
char spawn_arr[1000];
int current_block;





