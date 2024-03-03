#define _CRT_SECURE_NO_WARNINGS

#include"list.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

extern int ContaVette(const Item* i) {
	if (i == NULL)
		return 0;
	if (ListIsEmpty(i))
		return 0;

	int count = 0; //perchè l'ultimo è sempre vetta
	Item* copy1 = i;

	while (true) {
		
		if (copy1->next == NULL)
			break;

		Item* copy2 = copy1;
		ElemType *val = ListGetHeadValue(copy1);

		while(true){
			if (copy2->next == NULL) { //se sono arrivato alla fine significa che è vetta
				count++;
				break;
			}

			if (ElemCompare(val, &copy2->next->value) <= 0) //se trovo che è minore interrompo, non è vetta
				break;
			else
				copy2 = copy2->next; // se ancora valido avanzo
		}

		copy1 = copy1->next;

	}

	return count + 1;
}

/*
int main(void) {
	Item* list = malloc(sizeof(Item));
	list->value = 20;

	list->next = malloc(sizeof(Item));
	list->next->value = 10;

	list->next->next = malloc(sizeof(Item));
	list->next->next->value = 9;

	list->next->next->next = NULL;

	int n = 4;

	int vette = ContaVette(list);

	return 0;
}
*/