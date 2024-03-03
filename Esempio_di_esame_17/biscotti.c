#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>

void AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size,
	int *scelte, int* maxHappy, int i) {

	if (i == bis_size) { //sono andato appena oltre, ritorno dopo aver controllato quanti sono felici
		int countHappy = 0;
		int sum = 0;
		for (int j = 0; j < bam_size; j++) {
			sum = 0;
			for (int k = 0; k < bis_size; k++) { //se il biscotto è dato al bambino attuale aumento la sua somma
				if (scelte[k] == j)
					sum += bis[k];
			}

			if (sum >= bam[j]) //se il bambino ha abbastanza grammi di biscotti lo conto
				countHappy++;
		}

		if (countHappy > *maxHappy) //se ho un nuovo numero massimo aggiorno
			*maxHappy = countHappy;
		return;
	}

	for (int j = 0; j < bam_size; j++) {
		scelte[i] = j;
		AssegnaBiscottiRec(bam, bam_size, bis, bis_size, scelte, maxHappy, i + 1);
	}
}

int AssegnaBiscotti(const int* bam, size_t bam_size,
	const int* bis, size_t bis_size) {
	if (bam == NULL || bam_size == 0 || bis == NULL || bis_size == 0)
		return 0;

	int* scelte = calloc(bis_size, sizeof(int));
	//ogni biscotto è associato all'indice del bimbo
	int maxHappy = 0;

	AssegnaBiscottiRec(bam, bam_size, bis, bis_size, scelte, &maxHappy, 0);

	free(scelte);

	return maxHappy;
}

/*
int main(void) {

	int bam[] = { 10, 10, 10 };
	int bis[] = { 10, 12, 14 }; 
	size_t bam_size = 3;
	size_t bis_size = 3;

	int countHappy = AssegnaBiscotti(bam, bam_size, bis, bis_size);
}

*/