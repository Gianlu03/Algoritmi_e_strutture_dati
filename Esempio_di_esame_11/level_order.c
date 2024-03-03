#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

void findTreeMaxLevel(const Node* t, int *maxlevel, int i) {
	if (t == NULL)
		return;

	if (i > *maxlevel)
		*maxlevel = i;

	if(t->left != NULL)
		findTreeMaxLevel(t->left, maxlevel, i + 1);

	if (t->right != NULL)
		findTreeMaxLevel(t->right, maxlevel, i + 1);
}

void printTreePerLevel(const Node* t, int i, int leveltoPrint) {
	if (t == NULL)
		return;

	if (i == leveltoPrint) {
		printf("%d ", t->value);
	}

	if (t->left != NULL)
		printTreePerLevel(t->left, i + 1, leveltoPrint);

	if (t->right != NULL)
		printTreePerLevel(t->right, i + 1, leveltoPrint);
}

void LevelOrder(const Node* t) {
	if (t == NULL || TreeIsEmpty(t))
		return;

	int printLevel = 0;

	int maxlevel = 0;
	findTreeMaxLevel(t, &maxlevel, 0);

	while (printLevel <= maxlevel) {
		printTreePerLevel(t, 0, printLevel);
		printLevel++;
	}
}

/*
int main(void)
{
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
	
	LevelOrder(tree);

	return 0;
}
*/