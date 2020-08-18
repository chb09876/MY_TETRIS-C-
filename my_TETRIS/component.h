#pragma once
#include <stdbool.h>
#define pause system("pause")
#define cls system("cls")

//필드 구조체
struct location {
	bool shape;//0="  ", 1="■"
	bool ismove;//0=stop, 1=move
	bool iscontrol;//0=not, 1=controled

};