#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<ctype.h>
#include<math.h>

Node* CreateMinBinTreeRec(const ElemType* v, size_t v_size, size_t start, size_t end) {
	if (start >= end)
		return NULL;

	ElemType min = v[start];
	size_t indexMin = start;

	if(start < end - 1)
		for (int i = start + 1; i < end; i++) {
			if (ElemCompare(v+i,&min) == -1) {
				min = v[i];
				indexMin = i;
			}		
		}
	
	if (start == end - 1) //se ho solo un elemento, nodo senza figli
		return TreeCreateRoot(&min, NULL, NULL);

	else if (indexMin == start) //se è all'estremo sinistro, nodo con solo figlio destro
		return TreeCreateRoot(&min,
			NULL,
			CreateMinBinTreeRec(v, v_size, start + 1, end)
		);

	else if (indexMin == end - 1)
		return TreeCreateRoot(&min,
			CreateMinBinTreeRec(v, v_size, start, end - 1),
			NULL
		);

	else
		return TreeCreateRoot(&min,
			CreateMinBinTreeRec(v, v_size, start, indexMin),
			CreateMinBinTreeRec(v, v_size, indexMin + 1, end)
		);
}

Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0)
		return TreeCreateEmpty();

	size_t start = 0, end = v_size;

	Node *t = CreateMinBinTreeRec(v, v_size, start, end);

	return t;
}
