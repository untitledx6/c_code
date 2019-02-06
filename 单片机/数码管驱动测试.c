#include<reg51.h>
void delay (void);
void delay (void) {
	int i;
	for(i = 0; i < 30000; i++);
}
void main (void) {
	P1 = 0;
	while(1) {
		unsigned char b, a = 1;
		for(b = 0; b < 8; b++) {
			P0 = a;
			a = a << 1;
			delay();
		}
		delay();
		delay();
		delay();
	}
}
