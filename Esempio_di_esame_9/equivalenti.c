#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

void EquivalentiRec(const Node* t1, const Node* t2, bool *foundDifference) {
	if (foundDifference == true) //se ho trovato una sola differenza fermo tutto
		return;

	if (t1 == NULL && t2 == NULL) // se entrambi null sono a fine alberi, non significa differenza
		return;

	if (t1 == NULL && t2 != NULL || t1 != NULL && t2 == NULL) {
		*foundDifference = true;
		return;
	}

	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) { //se sono foglie uno deve essere multiplo dell'altro
		if (!(t1->value % t2->value == 0 || t2->value % t1->value == 0)) {
			*foundDifference = true;
			return;
		}
	}
	else if (!TreeIsLeaf(t1) && !TreeIsLeaf(t2)) { // se entrambi nodi e non foglie devono essere uguali
		if (ElemCompare(&t1->value, &t2->value) != 0) {
			*foundDifference = true;
			return;
		}
	}
	else if (TreeIsLeaf(t1) && !TreeIsLeaf(t2) || !TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		*foundDifference = true;
		return;
	} //se uno è foglia e l'altro no ho struttura diversa

	EquivalentiRec(t1->left, t2->left, foundDifference);
	EquivalentiRec(t1->right, t2->right, foundDifference);
}

bool Equivalenti(const Node* t1, const Node* t2) {
	if (t1 == NULL && t2 != NULL || t1 != NULL && t2 == NULL)
		return false;

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;

	bool foundDifference = false;
	EquivalentiRec(t1, t2, &foundDifference);

	return !foundDifference;
}

/*
int main(void) {
	ElemType e[] = { 1, 3, 4 };
	Node* t1 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1, NULL, NULL),
		TreeCreateRoot(e + 2, NULL, NULL)
	);

	ElemType f[] = { 1, 4, 3 };

	Node* t2 = TreeCreateRoot(f,
		TreeCreateRoot(f + 1, NULL, NULL),
		TreeCreateRoot(f + 2, NULL, NULL)
	);

	bool areEquiv = Equivalenti(t1, t2);

	return 0;
}
*/