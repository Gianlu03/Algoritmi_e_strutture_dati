#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

void ParentesiRec(int n, int* verso, int i, int *nsol, int nAperte, int nChiuse) {
	if (nChiuse > nAperte + 1 || nChiuse > n || nAperte > n)
		return;
	
	if (i > 2 * n - 1)
		return;
	
	if (nAperte == n && nChiuse == n) // ho una soluzione
	{
		*nsol += 1;
		for (int j = 0; j < 2 * n; j++)
			if (verso[j] == 1)
				printf("(");
			else
				printf(")");
		printf("\n");
		return;
	}
	else if (i == 2 * n && nAperte != nChiuse) return;


	verso[i] = -1;
	ParentesiRec(n, verso, i + 1, nsol, nAperte, nChiuse +1);
	verso[i] = 1;
	ParentesiRec(n, verso, i + 1, nsol, nAperte + 1, nChiuse);
	verso[i] = 0;//pulisco


}

int Parentesi(int n) {
	if (n < 0)
		return -1;

	if (n == 0)
		return 0;

	int* verso = calloc(n*2, sizeof(int));
	verso[0] = 1;
	verso[2 * n - 1] = -1;
	int nsol = 0;
	

	ParentesiRec(n, verso, 1, &nsol, 1, 1);

	free(verso);

	return nsol;
}


/*
int main(void) {
	Parentesi(3);
}
*/