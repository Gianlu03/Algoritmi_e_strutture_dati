#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>
/*
	valori da 1 a n+1 (strlen)
	no ripetizioni

	1) prova in ogni posizione ogni carattere da 1 a n+1 con un ciclo

	2) controlla se il numero è già usato o se non rispetta la regola, in quel caso pota subito il ramo

	3) se arrivo ad usare i elementi, arrivato alla strlen, allora ho una soluzione valida e stampo

*/

void RegoleRec(char* r, int* sequenza, int i, size_t len) {
	//caso base
	if (i > len)
		return;
	
	
	for (int j = 1; j <= len + 1; j++) {
		sequenza[i] = j;

		//Il primo è sicuramente valido, controllo se i successivi si ripetono e se rispettano le regole
		if (i >= 1) {
			//controllo se rispetta la regola
			if (sequenza[i] >= sequenza[i - 1] && (r[i-1] == 'D' || r[i-1] == 'd')) {
				continue;
			}
			else if (sequenza[i] <= sequenza[i - 1] && (r[i-1] == 'I' || r[i-1] == 'i')) {
				continue;
			}
		
			//controllo se già utilizzato
			bool isUsed = false;
			for (int k = 0; k < i; k++) {
				if (k == i) continue;
				
				if (sequenza[k] == sequenza[i]) {
					isUsed = true;
					break;
				}
			}
			if (isUsed == true) {
				continue;
			}
		}

		if (i == len) { // se i arriva a len significa che ho trovato una combinazione che funziona
			for (int j = 0; j < len+1; j++) {
				if (j > 0)
					printf(" ");
				printf("%d", sequenza[j]);
			}
			printf("\n");
		}

		//se superati tutti i controlli continuo la ricorsione(poi pulisco)
		RegoleRec(r, sequenza, i + 1, len);
	}
}

void Regole(const char* r) {
	size_t len = strlen(r);
	if (strcmp(r, "") == 0 || len == 0) {
		printf("1");
		return;
	}
	
	int* sequenza = calloc(len + 1, sizeof(int));

	RegoleRec(r, sequenza, 0, len);


	free(sequenza);
}

/*

int main(void) {

	Regole("DiDId");

	return 0;
}
*/