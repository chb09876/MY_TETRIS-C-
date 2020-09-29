#pragma once
#include <stdbool.h>
//메인메뉴
void mainmenu();

//커서 이동
void gotoxy(short x, short y);

void debug();

/*테트리스 관련함수 모음*/

//테트리스
void Tetris();

//시작 갱신
void init_update();

//정보 갱신
void info_update();

//패배조건 확인
void islose();

//화면 출력
void show_T();

//중력

void loc_update();

void moveright();

void moveleft();

void movedown();

void moveup();

void turnR();

void fix();

//블럭 스폰
void spawn_block(int num);