#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

int PotenzaRec(int a, int b)
{
	if (b == 1)
		return a;
	return a * PotenzaRec(a, b - 1);
}

int Potenza(int a, int b) {
	if (a == 0 && b == 0)
		return 1;
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;

	return PotenzaRec(a, b);
}

/*
int main(void) {

	int n = Potenza(, 3);
	return 0;

}
*/