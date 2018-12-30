#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define N 20 // 地图大小
int map[N][N]; //地图 
int head, tail; //头尾 
int direction; // 方向 
int egg; //蛋的位置
void move (); //移动 
int detection (); // 检测 
void new_egg (); //创建蛋 
void print (); //打印 
void initialize (); //初始化 
int reverse(); // 当前方向的反向 
void move () {
	int  t = detection();
	if(t == -1){
		printf("%d\n", head - 1);
		printf("game over!\n");
		getchar();
		exit(0);
	}
	else if(t == 1){
		switch(direction){
			case 2:
				map[0][head - N] = map[0][head] + 1;
				head = head - N;
				break;
			case 4:
				map[0][head - 1] = map[0][head] + 1;
				head = head - 1;
				break;
			case 6:
				map[0][head + 1] = map[0][head] + 1;
				head = head + 1;
				break;
			case 8:
				map[0][head + N] = map[0][head] + 1;
				head = head + N;
				break;
		}
		new_egg();
	}
	
	else{
		switch(direction){
			case 2:
				map[0][head - N] = map[0][head] + 1;
				head = head - N;
				break;
			case 4:
				map[0][head - 1] = map[0][head] + 1;
				head = head - 1;
				break;
			case 6:
				map[0][head + 1] = map[0][head] + 1;
				head = head + 1;
				break;
			case 8:
				map[0][head + N] = map[0][head] + 1;
				head = head + N;
				break;
		}
		if(map[0][tail] + 1 == map[0][tail - N]){
			map[0][tail] = 0;
			tail = tail - N;
		}
		else if(map[0][tail] + 1 == map[0][tail - 1]){
			map[0][tail] = 0;
			tail = tail - 1;
		}
		else if(map[0][tail] + 1 == map[0][tail + 1]){
			map[0][tail] = 0;
			tail = tail + 1;
		}
		else{
			map[0][tail] = 0;
			tail = tail + N;
		
		}
	}
}
int detection () {
	switch(direction){
		case 2:
			if(map[0][head - N] ==  -1){
				return 1;
			}
			else if(map[0][head - N] ==  0){
				return 0;
			}
			else{
				return -1;
			}
		case 4:
			if(map[0][head - 1] ==  -1){
				return 1;
			}
			else if(map[0][head - 1] ==  0){
				return 0;
			}
			else{
				return -1;
			}
		case 6:
			if(map[0][head + 1] ==  -1){
				return 1;
			}
			else if(map[0][head + 1] ==  0){
				return 0;
			}
			else{
				return -1;
			}
		case 8:
			if(map[0][head + N] ==  -1){
				return 1;
			}
			else if(map[0][head + N] ==  0){
				return 0;
			}
			else{
				return -1;
			}
	}
}
void new_egg () {
	srand((unsigned int)time(0));
	while(1){
		int t = rand();
		if(map[0][t % (N * N)]  == 0){
			map[0][t % (N * N)] = -1;
			break;
		}
	}
}
void print () {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] > 0){
				printf("* ");
			}
			else if(map[i][j] == -1){
				printf("o ");
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
}
void initialize () {
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == 0 || i == N - 1 || j == 0 || j == N - 1){
				map[i][j] = 1;
			}
			else{
				map[i][j] = 0;
			}
		}
	}
	map[0][N * N / 2 + 1] = 2;
	map[0][N * N / 2 + 2] = 3;
	head = N * N / 2 + 2;
	tail = N * N / 2 + 1;
	direction = 6;
	new_egg();
}
int reverse () {
	switch(direction){
		case 2:
			return 8;
		case 4:
			return 6;
		case 6:
			return 4;
		case 8:
			return 2;
	}
} 
 
int main (void) {	
	initialize();
	while(1){
		print();
		char c;
		if(kbhit()){
			c = getch();
			int t;
			switch(c){
				case 'w':
					t = 2;
					break;
				case 's':
					t = 8;
					break;
				case 'a':
					t = 4;
					break;
				case 'd':
					t = 6;
			}
			if(t == 2 || t == 4 || t == 6 || t == 8){
				if(t != reverse()){
					direction = t;
				}
			}
		}
		move();
		Sleep(500);
		system("cls");
	}
	return 0;
}
