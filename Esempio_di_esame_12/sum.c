#define _CRT_SECURE_NO_WARNINGS

#include"list.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

Item* listCopy(const Item *i) {
	Item* copy = ListCreateEmpty();
	Item* l = i;

	while (true) { //sicuramente una volta entra, perchè significa che non sono entrambe vuote se si arriva qui
		ElemType e = ElemCopy(&l->value);
		copy = ListInsertBack(copy, &e);

		if (l->next == NULL)
			break;

		l = l->next;
	}

	return copy;
}

Item* Sum(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2))
		return ListCreateEmpty();

	//se solo una è vuota, viene ritornata una copia della non vuotaa

	if (ListIsEmpty(i1) && !ListIsEmpty(i2))
		return listCopy(i2);

	if (!ListIsEmpty(i1) && ListIsEmpty(i2))
		return listCopy(i1);

	//se arrivo qui effettuo la somma

	Item* sum = ListCreateEmpty();
	Item* l1 = i1;
	Item* l2 = i2;
	bool l2Finished = false, l1Finished = false;
	int carry = 0;
	ElemType newEl;

	while (true) {

		if (!l1Finished && !l2Finished)
			newEl = l1->value + l2->value;
		else if (l1Finished && !l2Finished)
			newEl = l2->value;
		else if (!l1Finished && l2Finished)
			newEl = l1->value;

		if (carry == 1) {
			newEl += 1;
			carry = 0;
		}
		
		if (newEl >= 10) {
			carry = 1;
			newEl = newEl % 10;  //es: 18 -> memorizza 8 e 1 in riporto
			sum = ListInsertBack(sum, &newEl);
		}
		else
			sum = ListInsertBack(sum, &newEl); //se non ha raggiunto 10 la somma copia e basta

		if (l1->next == NULL)
			l1Finished = true;
		if (l2->next == NULL)
			l2Finished = true;;

		if (l1Finished && l2Finished) {

			if (carry == 1) {
				newEl = 1;
				sum = ListInsertBack(sum, &newEl); // se alla fine di 2 liste di uguale dimensione ho riporto aggiungo un 1 alla fine
			}

			break;
		}

		if (!l1Finished)
			l1 = l1->next;
		if (!l2Finished)
			l2 = l2->next;
		
	}
	return sum;

}



/*
int main(void) {

	Item* list = malloc(sizeof(Item));  //912 + 912 = 1824 -> 4281
	list->value = 2;

	list->next = malloc(sizeof(Item));
	list->next->value = 1;

	list->next->next = malloc(sizeof(Item));
	list->next->next->value = 9;

	list->next->next->next = NULL;


	Item* list2 = malloc(sizeof(Item));
	list2->value = 2;

	list2->next = malloc(sizeof(Item));
	list2->next->value = 1;

	list2->next->next = NULL;

	Item* sum = Sum(list, list2);

	return 0;
}
*/