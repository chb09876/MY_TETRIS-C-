#pragma once

//메인메뉴
void mainmenu();

//화면 클리어
void clear();

//커서 이동
void gotoxy(short x, short y);

/*테트리스 관련함수 모음*/

//테트리스
void Tetris();

//패배조건 확인
void islose(struct location f[][10]);

//화면 출력
void show_T(struct location f[][10]);