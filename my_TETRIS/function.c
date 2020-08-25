#define _CRT_SECURE_NO_WARNINGS

#include "component.h"
#include "function_name.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/*유틸함수모음*/

//커서 이동
void gotoxy(short x, short y) {
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

//디버깅
void debug() {
	printf("block num=%d\n", current_block);
	printf("block[0].y=%d block[0].x=%d\n", block[0].y, block[0].x);
	printf("block[1].y=%d block[1].x=%d\n", block[1].y, block[1].x);
	printf("block[2].y=%d block[2].x=%d\n", block[2].y, block[2].x);
	printf("block[3].y=%d block[3].x=%d\n", block[3].y, block[3].x);
	printf("spawn_point=%d\n", spawn_point);
	printf("move_R=%d\n", move_R);
	printf("move_L=%d\n", move_L);
	printf("move_D=%d\n", move_D);
}

//메인메뉴
void mainmenu() {
	while (1) {
		printf("모드를 선택하세요\n");
		printf("1. TETRIS\n");
		printf("[Esc] to EXIT\n");
		switch (_getch()) {
		case '1':
			Tetris();
			break;
		case 27:
			return ;
		}
	}
}

//테트리스
void Tetris() {
	/*디버그모드*/
	cls;
	char deb;
	init_update();
	spawn_block(3);
	show_T();
	debug();
	while (1) {
		switch (deb=_getch()) {
		case 'w':
			moveup();
			break;
		case 'd':
			moveright();
			break;
		case 'a':
			moveleft();
			break;
		case 's':
			movedown();
			break;
		case ' ':
			fix();
			break;
		default:
			spawn_block(deb-'0');
			break;
		}
		show_T();
		debug();
	}
}



/*이동관련함수*/

//중력
void movedown() {
	if (move_D == 1) {
		for (int i = 0; i < 4; i++) {
			field[block[i].y][block[i].x] = field_void;
			field[block[i].y + 1][block[i].x] = field_controled;
		}
	}
	info_update();
}

//하드드랍
void harddrop() {

}

//왼쪽이동
void moveleft() {
	if (move_L == 1) {
		for (int i = 0; i < 4; i++) {
			field[block[i].y][block[i].x] = field_void;
			field[block[i].y][block[i].x - 1] = field_controled;
		}
	}
	info_update();
}

//오른쪽이동
void moveright() {
	if (move_R == 1) {
		for (int i = 3; i >=0; i--) {
			field[block[i].y][block[i].x] = field_void;
			field[block[i].y][block[i].x +1] = field_controled;
		}
	}
	info_update();
}

//위로이동(디버그용)
void moveup() {
	for (int i = 3; i >= 0; i--) {
		field[block[i].y][block[i].x] = field_void;
		field[block[i].y-1][block[i].x] = field_controled;
	}
	info_update();
}
void turnR() {
	
}
/*정보갱신함수*/

//시작 갱신
void init_update() {
	//필드설정
	for (int i = 0; i < 21; i++) {
		for (int ii = 0; ii < 10; ii++) {
			field[i][ii] = field_void;
		}
	}
	move_R = 1;
	move_L = 1;
	move_D = 1;
	//블록스폰배열설정
	srand(time(NULL));
	for (int i = 0; i < 1000; i+=7) {
		spawn_arr[i] = rand() % 7 + 1;
		for (int n = 1; n < 7; n++) {
			while (1) {
				int cnt = 0;
				spawn_arr[i + n] = rand() % 7 + 1;
				for (int m = 0; m < n; m++) {
					if (spawn_arr[i + n] != spawn_arr[i + m]) {
						cnt++;
						continue;
					}
				}
				if (cnt == n) {
					break;
				}
			}
		}
	}
}

//정보 갱신
////////////////////////////
//기능목록
//위치정보 업뎃
//move_R,move_L,move_D 체크
//바닥에 닿을시 몇초후 컨트롤 벗어나야됨
void info_update() {
	//위치정보 업뎃
	loc_update();
	//move_D 업뎃
	//control==1인블록 밑에 control==0인 블록이 존재하는지 확인
	//control==1인 블록이 y=20에 존재할때 move_D=0
	for (int n = 0; n < 4; n++) {
		if (block[n].y == 20) {
			move_D = 0;
			break;
		}
		else if (field[block[n].y + 1][block[n].x].shape == 1 && field[block[n].y + 1][block[n].x].control == 0) {
			move_D = 0;
			break;
		}
		else
			move_D = 1;
	}
	//move_R업뎃
	//control==1인 블록 오른쪽에 블록 존재 확인
	//control==1인 블록이 x=9에 존재할시
	for (int n = 0; n < 4; n++) {
		if (block[n].x == 9) {
			move_R = 0;
			break;
		}
		else if(field[block[n].y][block[n].x+1].shape == 1 && field[block[n].y][block[n].x+1].control == 0){
			move_R = 0;
			break;
		}
		else 
			move_R = 1;
	}
	// move_L업뎃
	//control==1인 블록 왼쪽에 블록 존재
	//control ==1 인 블록이 x=0에 존재
	for (int n = 0; n < 4; n++) {
		if (block[n].x == 0) {
			move_L = 0;
			break;
		}
		else if (field[block[n].y][block[n].x - 1].shape == 1 && field[block[n].y][block[n].x - 1].control == 0) {
			move_L = 0;
			break;
		}
		else
			move_L = 1;
	}
	//스폰포인트설정
	for (int i = 0; i < 10; i++) {
		if (field[2][i].shape == 1 && field[2][i].control == 0) {
			spawn_point = 0;
			break;
		}
		else
			spawn_point = 1;
	}
}

//컨트롤 해제/픽스
void fix() {
	for (int i = 0; i < 4; i++) {
		field[block[i].y][block[i].x].control = 0;
	}
	current_block = 0;
	info_update();
}

//위치 업뎃
void loc_update() {
	int n = 0;
	for (int i = 20; i >= 0; i--) {
		for (int ii = 0; ii < 10; ii++) {
			if (field[i][ii].control == 1) {
				block[n].y = i;
				block[n].x = ii;
				n++;
			}
		}
	}
}

//블럭 스폰
void spawn_block(int num) {
	switch (num) {
	case 1://I블록
		current_block = 1;
		field[spawn_point][3] = field_controled;
		field[spawn_point][4] = field_controled;
		field[spawn_point][5] = field_controled;
		field[spawn_point][6] = field_controled;
		break;
	case 2://O블록
		current_block = 2;
		field[spawn_point + 1][4] = field_controled;
		field[spawn_point + 1][5] = field_controled;
		field[spawn_point][4] = field_controled;
		field[spawn_point][5] = field_controled;
		break;
	case 3://T블록
		current_block = 3;
		field[spawn_point + 1][3] = field_controled;
		field[spawn_point + 1][4] = field_controled;
		field[spawn_point + 1][5] = field_controled;
		field[spawn_point][4] = field_controled;
		break;
	case 4://L블록
		current_block = 4;
		field[spawn_point + 1][3] = field_controled;
		field[spawn_point + 1][4] = field_controled;
		field[spawn_point + 1][5] = field_controled;
		field[spawn_point][5] = field_controled;
		break;
	case 5://J블록
		current_block = 5;
		field[spawn_point + 1][3] = field_controled;
		field[spawn_point + 1][4] = field_controled;
		field[spawn_point + 1][5] = field_controled;
		field[spawn_point][3] = field_controled;
		break;
	case 6://z블록
		current_block = 6;
		field[spawn_point + 1][4] = field_controled;
		field[spawn_point + 1][5] = field_controled;
		field[spawn_point][3] = field_controled;
		field[spawn_point][4] = field_controled;
		break;
	case 7://s블록
		current_block = 7;
		field[spawn_point + 1][3] = field_controled;
		field[spawn_point + 1][4] = field_controled;
		field[spawn_point][4] = field_controled;
		field[spawn_point][5] = field_controled;
		break;
	}
	info_update();
}

//패배조건 체크
void islose() {
	for (int i = 0; i < 10; i++) {
		if (field[0][i].shape == 1) {
			cls;
			printf("YOU LOSE ㅋㅋㅋ\n");
			break;
		}
	}
}

//출력함수
void show_T() {
	gotoxy(0, 0);
	for (int y = 1; y < 21; y++) {
		for (int x = 0; x < 10; x++) {
			if (field[y][x].shape == 1) {
				printf("■");
			}
			else {
				printf("□");
			}
		}
		printf("\n");
	}
}