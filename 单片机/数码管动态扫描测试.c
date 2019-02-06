#include<reg51.h>
void main (void) {
	unsigned char num[10] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144};
	while(1) {
		unsigned char b, a = 128;
		for(b = 0; b < 8; b++) {
			P0 = 255;// 这一句上拉很关键 
			P1 = ~a;
			P0 = num[b];
			a = a>>1;
		}
	}
}
