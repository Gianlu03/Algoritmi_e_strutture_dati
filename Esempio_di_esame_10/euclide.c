#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

int MCDRec(int m, int n) {
	if (n == 0)
		return m;

	return MCDRec(n, m%n);
}

int MCD(int m, int n) {
	if (m == n)
		return m;
	if (m > n)
		return MCDRec(m, n);
	//else
	return MCDRec(n, m);

}


/*
int main(void) {

	printf("%d", MCD(8, 42));
	return 0;
}

*/