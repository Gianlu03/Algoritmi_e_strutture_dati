#define _CRT_SECURE_NO_WARNINGS

#include"minheap.h"

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>

extern bool Pop(Heap* h, ElemType* e) {
	if (h == NULL || h->size == 0)
		return false;

	*e = h->data[0];
	/*else if (h->size == 2) {
		h->data[0] = h->data[1];
		h->data = realloc(h->data, sizeof(ElemType));
		h->size = 1;
	}*/
	ElemSwap(h->data, h->data + h->size - 1); //scambio con l'ultimo elemento
	h->data = realloc(h->data, sizeof(ElemType)*(h->size-1));
	h->size--;
	HeapMinMoveDown(h, 0);

	return true;

}
