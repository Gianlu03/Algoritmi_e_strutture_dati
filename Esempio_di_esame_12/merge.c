#define _CRT_SECURE_NO_WARNINGS

#include"minheap.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

extern Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap *merged = HeapCreateEmpty();

	for (int i = 0; i < h1->size; i++) {
		HeapMinInsertNode(merged, h1->data + i);
	}

	for (int i = 0; i < h2->size; i++) {
		HeapMinInsertNode(merged, h2->data + i);
	}

	return merged;
}

/*
int main(void) {
	
	ElemType v1[] = { 1, 4, 5, 6, 7, 8, 9 , 10};
	ElemType v2[] = { 1, 2, 3, 7, 11, 12, 13 , 20 };
	size_t size = 8;

	Heap* h1 = HeapCreateEmpty();
	Heap* h2 = HeapCreateEmpty();

	h1->data = v1;
	h2->data = v2;
	h1->size = h2->size = size;

	MergeHeap(h1, h2);
	return 0;
}*/