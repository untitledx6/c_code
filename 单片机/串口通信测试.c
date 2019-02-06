sfr P0 = 0x80;
sbit P0_0 = P0 ^ 0;
sbit P0_1 = P0 ^ 1;
sbit P0_6 = P0 ^ 6;
sbit P0_7 = P0 ^ 7;
void main (void) {
	P0_7 = 1;
	P0_6 = 0;
	P0_0 = 1;
	P0_1 = 1;
	while(1) {
		if(P0_7 == 0 && P0_6 == 0) {
			P0_1 = 0;
		}
		else if(P0_7 == 1 && P0_6 == 0){
			P0_1 = 1;
		}
	}
}
