#define NUM 500
sfr P0 = 0x80;
sbit P0_0 = P0 ^ 0;
sbit P0_1 = P0 ^ 1;
unsigned char j;
int temp;
void bright (unsigned char t);
//id delay (void);
void bright (unsigned char t) {
	unsigned char i;
	for(i = 0; i < t; i++) P0_1 = 0;
	for(i = t; i < 100; i++) P0_1 = 1;
}
/*void delay (void) {
	int c;
	for(c = 0; c < 10000; c++);
}*/
void main (void) {
	P0_0 = 1;
//	unsigned char j;
	while(1) {
		for(j = 0; j < 100; j++) {
			for(temp = 0; temp < NUM; temp++) bright(j);
		}
		for(j = 100; j > 0; j--) {
			bright(j);
			for(temp = 0; temp < NUM; temp++) bright(j);
		}
	}
}
