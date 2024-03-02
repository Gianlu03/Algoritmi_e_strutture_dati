#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

void FrazioneEgiziaRec(int n, int d, int c) {
	int denUnitaria = d/n + (d%n != 0);
	if (c == 0)
		printf("1/%d", denUnitaria);
	else
		printf(" + 1/%d", denUnitaria);

	if (d % n == 0)
		return;

	FrazioneEgiziaRec(n*denUnitaria - d, d * denUnitaria, c+1);
}

void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}
	
	FrazioneEgiziaRec(n, d, 0);
}

/*
int main(void) {
	FrazioneEgizia(7, 24);
}
*/