#include<reg51.h>
void delay (void);
void delay (void) {
	int i;
	for(i = 0; i < 32000; i++);
}
void main (void) {
	unsigned char num[10] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144};
	// 显示带小数点的数就num[i] - 128 即可 
	P1 = 0;
	while(1) {
		unsigned char b;
		for(b = 0; b < 10; b++) {
			P0 = num[b];
			delay();
			delay();
		}
		delay();
		delay();
		delay();
		delay();
	}
}
