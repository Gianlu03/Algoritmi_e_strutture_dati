#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void IsomorfiRec(const Node* left1, const Node* right1, const Node* left2, const Node* right2, bool *isIso) {
	if (left1->left == NULL && left2->left != NULL || left1->right != NULL && left2->right == NULL ||
		right1->left == NULL && right2->left != NULL || right1->right != NULL && right2->right == NULL) {
		*isIso = false;
		return;
	}
	
	if (right1 == NULL && right2 == NULL && left1 == NULL && left2 == NULL) // se tutto NULL sono arrivato alla fine del ramo
		return;
	
	if (right1 == NULL && right2 == NULL)
		if (ElemCompare(&left1->value, &left2->value) == 0)
			IsomorfiRec(left1->left, left1->right, left2->left, left2->right, isIso);
		else
			*isIso = false;
	
	//Se un nodo ha un solo figlio è di sicuro quello di sinistra?

	//se sono uguali nel livello continuo la ricerca
	if (ElemCompare(&left1->value, &left2->value) == 0 && ElemCompare(&right1->value, &right2->value) == 0)  {
		
		IsomorfiRec(left1->left, left1->right, left2->left, left2->right, isIso);
		IsomorfiRec(right1->left, right1->right, right2->left, right2->right, isIso);
	}
	else if (ElemCompare(&left1->value, &right2->value) == 0 && ElemCompare(&right1->value, &left2->value) == 0) {
		IsomorfiRec(left1->left, left1->right, right2->left, right2->right, isIso);
		IsomorfiRec(right1->left, right1->right, left2->left, left2->right, isIso);
	}

}

bool Isomorfi(const Node* t1, const Node* t2) {
	if (t1 == NULL && t2 == NULL)
		return false; 
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	else if (TreeIsEmpty(t1)) // se solo uno dei 2 è vuoto sicuramente non sono isomorfi
		return false;
	else if (TreeIsEmpty(t2))
		return false;

	Node* copy1 = t1;
	Node* copy2 = t2;
	bool isIso = true;

	if (ElemCompare(&(copy1->value), &(copy2->value)) == 0) { //se le 2 radici sono uguali allora richiamo con i 4 sottoalberi
		IsomorfiRec(copy1->left, copy1->right, copy2->left, copy2->right, &isIso);
	}
	else
		return false; // se la radice è diversa posso già interrompere

	return isIso;
}

/*
int main(void) {
	Isomorfi(NULL, NULL);
}
*/