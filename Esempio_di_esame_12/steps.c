#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

void StepsRec(int n, int* sequenza, int sum, int i, int* nsol) {
	if(sum == n){ //caso valido, stampa fino a <i
		*nsol += 1;
		printf("[");
		for (int j = 0; j < i - 1; j++) {
			printf("%d, ", sequenza[j]);
		}
		printf("%d], ", sequenza[i - 1]);
		return;
	}

	if (sum > n) { //è andato oltre, non valido
		return;
	}

	for (int j = 1; j <= 3; j++) {
		sequenza[i] = j;
		sum = 0;
		for (int k = 0; k <= i; k++)
			sum += sequenza[k];

		if (sum > n) {
			sequenza[i] = 0;
			continue;
		}

		StepsRec(n, sequenza, sum, i + 1, nsol);
	}
	
}


int Steps(int n) {
	if (n <= 0)
		return 0;

	int* sequenza = calloc(n, sizeof(int));
	int nsol = 0;

	StepsRec(n, sequenza, 0, 0, &nsol);

	free(sequenza);
	return nsol;
}

