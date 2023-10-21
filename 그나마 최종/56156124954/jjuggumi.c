#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define	DATA_FILE	"jjuggumi.dat"

int jjuggumi_init(void);

// low 이상 high 이하 난수를 발생시키는 함수
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("플레이어 수: ");
	scanf_s("%d", &n_player);

	n_alive = n_player;
	for (int i = 0; i < n_player; i++) {
		player[i] = true;
	}
	return 0;
}
void intro(void);
void intro(void) {
	printf("00000000000000000000000000000000000000000000000000000000\n");
	Sleep(10);
	printf("00000000///00000000//000000////////////////000//0000000000000000000000000000000\n"); Sleep(10);
	printf("0000000//0//0000000//0000000000000//0000000000//0000000000000000\n"); Sleep(10);
	printf("000000//000//000000//000000000000//0//00000000//00000000000000000\n"); Sleep(10);
	printf("00000//00000//00000//00000000000//000//0000000/////0000000000000000\n"); Sleep(10);
	printf("0000//0000000//0000//0000000000//00000//000000//0000000000000\n"); Sleep(10);
	printf("000//000000000//000//000000000//0000000//00000//00000000000000\n"); Sleep(10);
	printf("0000000000000000000//0000000000000000000000000//000000000000\n"); Sleep(10);
	printf("0000000000000000000//000000000000000000000000000000000000\n"); Sleep(10);
	printf("0000000000000000000//000000000000////////////////0000000000000000000000000\n"); Sleep(10);
	printf("0000000000000000000//00000000000000000000000000//00000000000\n"); Sleep(10);
	printf("00000000000000000000000000000000000000000000000//000000000\n"); Sleep(10);
	printf("00000000000000000000000000000000000000000000000000000000\n"); Sleep(10);
	Sleep(1000);
}
void ending(void);
void ending(void) {
	int count_py=0;
	int winer;
	for (int i = 0; i < n_player; i++) {

		if (player[i] == true) {
			count_py++;

		}

	}
	if (count_py > 1) {
		printf("우승자를가리지못했습니다.");


	}
	if (count_py == 1) {
		for (int i = 0; i < n_player; i++) {
			if (player[i] == true) {
				printf("우승자는 %d님 입니다",i );
			}
		}
	}
}
int main(void) {
	jjuggumi_init();
	intro();
	//sample();
	mugunghwa();
	//nightgame();
	//juldarigi();
	//jebi();
	ending();
	return 0;
}
