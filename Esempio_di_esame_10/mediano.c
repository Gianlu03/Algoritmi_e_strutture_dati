#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<float.h>

void MedianoRec(const Node* t, int* count, double *median, int size) {
	*count += 1;
	if (size % 2 != 0)
		if (*count == size / 2) {
			*median = t->value;
		}

	if(size % 2 == 0)
		if (*count == size / 2  || *count == size / 2 + 1) {
			*median += t->value;
		}
		
	if (t->left != NULL)
		MedianoRec(t->left, count, median, size);
	if(t->right != NULL)
		MedianoRec(t->right, count, median, size);

}

void contaNodiRec(const Node* t, int* count) {
	*count += 1;
	if (t->left != NULL)
		contaNodiRec(t->left, count);
	if (t->right != NULL)
		contaNodiRec(t->right, count);
}

extern double Mediano(const Node* t) {
	if (t == NULL || TreeIsEmpty(t))
		return DBL_MAX;

	int sizeLeft = 0;
	contaNodiRec(t->left, &sizeLeft);
	int sizeRight = 0;
	contaNodiRec(t->right, &sizeRight);

	if (sizeLeft == sizeRight)
		return (double)t->value;

	double mediana = 0;
	int count = 0;
	MedianoRec(t, &count, &mediana, size);

	if (size % 2 != 0)
		return mediana;
	else
		return mediana / 2.0;
}

/*
int main(void) {
	ElemType e[] = { 12, 4, 21 ,0 ,2, 77, 8, 9, 5, 18 };
	Node* tree = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3,
				TreeCreateRoot(e + 5, NULL, NULL),
				TreeCreateRoot(e + 6, NULL, NULL)
			),
			TreeCreateRoot(e + 4,
				TreeCreateRoot(e + 7, NULL, NULL),
				NULL
			)
		),
		TreeCreateRoot(e + 2,
			TreeCreateRoot(e + 8, NULL, NULL),
			TreeCreateRoot(e + 9, NULL, NULL)
		));

	double m = Mediano(tree);
	return 0;
}
*/


