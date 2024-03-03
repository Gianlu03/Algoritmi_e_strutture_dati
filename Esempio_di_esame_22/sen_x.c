#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>

int fattoriale(int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	return n * fattoriale(n - 1);
}

double senoRec(int i, double x, int n) {
	if (n > i)
		return 0;
	return (pow(-1, n) * pow(x, 2*n + 1) / fattoriale(2*n + 1)) + senoRec(i, x, n + 1);
}

int main(int argc, char** argv) {
	if (argc != 3)
		return 1;
	
	char* endptr;
	double x = strtod(argv[1], &endptr);

	int i = atoi(argv[2]);

	if (i < 0) return 1;

	double seno = senoRec(i, x, 0);

	printf("%f", seno);

	return 0;
}