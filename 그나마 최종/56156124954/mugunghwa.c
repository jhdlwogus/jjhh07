#include "jjuggumi.h"
#include "canvas.h"
#include "keyin.h"
#include <stdio.h>
#include <Windows.h>


#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_LEFT	2
#define DIR_RIGHT	3


int px[PLAYER_MAX], py[PLAYER_MAX], period[PLAYER_MAX];  // �� �÷��̾� ��ġ, �̵� �ֱ�

void mugumghwe_init(void);
void move_manual(key_t key);
void move_random(int i, int dir);
void move_tail(int i, int nx, int ny);


void mugumghwe_init(void) {//�÷��̾� ���� �������� �������� �ٲ���
	map_init(10, 40);
	int x, y;
	for (int i = 0; i < n_player; i++) {
		// ���� �ڸ��� ������ �ٽ� ����
		do {
			x = 6-i;
			y = 38;
		} while (!placable(x, y));
		px[i] = x;
		py[i] = y;
		period[i] = randint(100, 500);

		back_buf[px[i]][py[i]] = '0' + i;  // (0 .. n_player-1)

	}

	
}


void move_manual(key_t key) {//�����ϴ� �ڵ�!
	// �� �������� ������ �� x, y�� delta
	static int dx[4] = { -1, 1, 0, 0 };
	static int dy[4] = { 0, 0, -1, 1 };

	int dir;  // ������ ����(0~3)
	switch (key) {
	case K_UP: dir = DIR_UP; break;
	case K_DOWN: dir = DIR_DOWN; break;
	case K_LEFT: dir = DIR_LEFT; break;
	case K_RIGHT: dir = DIR_RIGHT; break;
	default: return;
	}

	// �������� ���� �ڸ�
	int nx, ny;
	nx = px[0] + dx[dir];
	ny = py[0] + dy[dir];
	if (!placable(nx, ny)) {
		return;
	}

	move_tail(0, nx, ny);
}
void move_random(int player, int dir) {
	int p = player;  // �̸��� ��...
	int nx, ny;  // �������� ������ ���� �ڸ�

	// ������ ������ ���� ���� ���ٰ� ����(���� ������ ����)	
	
	do {
		nx = px[p] + randint(-1, 1);
		ny = py[p] + randint(-1, 1);
	} while (!placable(nx, ny));
	
	/*
	do {
		int move_p=0;
		move_p=randint(1,10 );
		if (move_p < 7) {

			nx = px[p] - 1;
		}
		else if (move_p < 8) {
			ny = py[p] - 1;

		}
		else if (move_p < 9) {
			
			ny = py[p] + 1;
		}
		else {
			

		}

		

	} while (!placable(nx, ny));
	

	*/


	move_tail(p, nx, ny);
}


// back_buf[][]�� ���
void move_tail(int player, int nx, int ny) {
	int p = player;  // �̸��� ��...
	back_buf[nx][ny] = back_buf[px[p]][py[p]];
	back_buf[px[p]][py[p]] = ' ';
	px[p] = nx;
	py[p] = ny;
}



void mugunghwa(void) {
	int p = player;
	int nx, ny;
	int jj=0;
	tick = 0;
	mugumghwe_init();
	system("cls");
	display();
	gotoxy(5, 2);
	printf("#");
	gotoxy(3, 2);
	printf("#");
	gotoxy(4, 2);
	printf("#");
	back_buf[5][2];
	back_buf[3][2];
	back_buf[4][2];
	while (true){

		key_t key = get_key();
		if (key == K_QUIT) {
			break;
		}
		else if (key != K_UNDEFINED) {
			move_manual(key);
		}

		// player 1 ���ʹ� �������� ������(8����)
		for (int i = 1; i < n_player; i++) {
			if (tick % period[i] == 0) {
				move_random(i, -1);
			}
		}
		display();
		Sleep(10);

		/*do {
			if (py[p] == 2) {
				if(px[p] == 2) {
				}
				if (px[p] == 6) {

				}
			}
			if (py[p] == 3) {
				if (px[p] == 5) {
				}
				if (px [p] == 3) {


				}
				if (px [p] == 4) {

				}
			}
		} while (1);
		
		*/
		gotoxy(10, 0);
		if (tick % 1000 == 0) {
			printf("��");

		}gotoxy( 10, 4);
		if (tick % 2000 == 0) {
			printf("��");

		}gotoxy(10, 8);
		if (tick % 3000 == 0) {
			printf("ȭ");

		}gotoxy(10, 12);
		if (tick % 4000 == 0) {
			printf("��");

		}gotoxy(10, 16);
		if (tick % 5000 == 0) {
			printf("��");

		}gotoxy(10, 20);
		if (tick % 6000 == 0) {
			printf("��");
			gotoxy(10, 24);
		}if (tick % 7000 == 0) {
			printf("��");
			gotoxy(10, 28);
		}if (tick % 80000 == 0) {
			printf("��");

		}gotoxy(10, 32);
		if (tick % 9000 == 0) {
			printf("��");

		}gotoxy(10, 36);
		if (tick % 10000 == 0) {
			printf("��");
			jj++;
		}
		if (  jj=1) {
			gotoxy(10, 0);
			printf("                                                 ");
			jj = 0;
		}
		
		tick += 1000;
	}
	
}
