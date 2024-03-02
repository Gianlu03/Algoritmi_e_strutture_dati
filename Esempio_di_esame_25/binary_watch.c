#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<stdint.h>

void ValidTimesRec(uint8_t n, int *bit, int BitOn, int i) {
	if (BitOn > n) return;

	if (BitOn == n) {
		int min = 0, h = 0;

		for (int j = 0; j < 5; j++) //calcolo ore
			if (bit[j] == 1)
				h += pow(2, j);

		for (int j = 5; j < 11; j++) //calcolo min
			if (bit[j] == 1)
				min += pow(2, j - 5); //devo scalare di 5 indietro

		if (min < 60 && h < 24)
			printf("%02d:%02d, ", h, min);
		
		return; //ritorno perchè prenderei più bit richiamando
	}

	if (i >= 11) return;

	bit[i] = 0;
	ValidTimesRec(n, bit, BitOn, i + 1);
	bit[i] = 1;
	ValidTimesRec(n, bit, BitOn + 1, i + 1);
	bit[i] = 0;
}

void ValidTimes(uint8_t n){
	if (n > 11) return;

	//da bit[0] a bit[4] l'ora, da bit[5] a bit[10] i minuti
	//1 2 4 8 16 ore (pow tra 2 e i)
	//1 2 4 8 16 32 minuti (pow tra 2 e i - 5
	int* bit = calloc(11, sizeof(int));
	
	ValidTimesRec(n, bit, 0, 0);

	free(bit);
}


int main(void) {

	ValidTimes(9);
	return 0;
}