#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

void InsertionSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0)
		return;

	for (int i = 1; i < v_size; i++) {
		if (v[i] < v[i - 1]) { // se minore del precedente controllo in che posizione devo inserirlo, per poi mettercelo
			int pos = 0;
			while (v[i] >= v[pos])
				pos++;

			int tmp = v[i];

			for (int k = i; k > 0; k--) {
				v[k] = v[k - 1];
			}

			v[pos] = tmp;
		}
	}
}


int main(void) {

	int v[] = {5, 3, 7, 9, 8, 1};

	InsertionSort(v, 6);

	return 0;
}
