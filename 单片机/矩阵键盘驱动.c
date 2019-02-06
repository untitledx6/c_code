#include<reg51.h>
void main (void) {
		while(1) {
			P2 = 240;
			if (P2 != 240) {
				P2 = 15;
				if(P2 != 15) {
					P0 = 191;
				}
			} 
			else if (P2 == 240 || P2 == 15) {
				P0 = 255;
			}
		} 
}
