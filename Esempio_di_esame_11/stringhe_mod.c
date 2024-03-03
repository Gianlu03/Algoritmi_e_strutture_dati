#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

BackTrackStrModRec(int n, int k, char *stringa, int i) {
	if (i == k) {
		printf("{");
		for (int j = 0; j < k; j++)
			printf("%c", stringa[j]);
		printf("}, ");
		return;
	}

	for (int j = 0; j < n; j++) {
		int ascii = 97 + j;
		stringa[i] = ascii;

		BackTrackStrModRec(n, k, stringa, i + 1);
	}



}

extern void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26 || k <= 0)
		return;

	char *stringa = calloc(k+1, sizeof(char));

	BackTrackStrModRec(n, k, stringa, 0);

	free(stringa);
}


//a = 97 ascii

/*
int main(void) {
	int n = 2;
	int k = 3;
	BacktrackStrMod(n, k);
}
*/