#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

int massimo(int a, int b) {
	if (a >= b)
		return a;
	return b;
}

int minimo(int a, int b) {
	if (a <= b)
		return a;
	return b;
}


/*E' meglio se un cacciatore prende la preda più a sinstra possibile libera, lasciando quelle a destra per i prossimi cacciatori*/

void CacciatorePredaRec(const char* v, size_t v_size, int u, int *cattura, int index) {
	if (index == v_size)
		return;
	
	//se ho un cacciatore controllo se può catturare, la preda va diretta al richiamo ricorsivo
	if (v[index] == 'c' || v[index] == 'C') {
		//se arrivo qui ho un cacciatore

		int start = massimo(0, index - u);
		int finish = minimo(v_size, index + u + 1);

		for (int i = start; i < finish; i++) {
			//se trovo una preda libera aggiorno i valori e fermo il ciclo
			if (v[i] == 'P' || v[i] == 'p')
				if (cattura[i] == -1) {
					cattura[i] = -2; //preda catturata
					cattura[index] = i; //cacciatore acquisisce indice preda
					break;
				}
		}
	}

	CacciatorePredaRec(v, v_size, u, cattura, index + 1);
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {
	if (v == NULL || v_size == 0)
		return NULL;
	
	int* cattura = malloc(sizeof(int) * v_size);

	for (int i = 0; i < v_size; i++) {
		cattura[i] = -1;
	}
		
	int index = 0;
	CacciatorePredaRec(v, v_size, u, cattura, index);

	return cattura;

}


/*
int main(void) {

	char v[] = { 'P', 'C', 'C', 'P', 'P', 'C' };
	int v_size = 6;
	int u = 2;

	int *cattura = CacciatorePreda(v, v_size, u);

	return 0;
}
*/