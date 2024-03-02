#include"shift.h"

Item* ShiftN(Item* list, size_t n) {
	if (list == NULL || ListIsEmpty(list))
		return NULL;

	if (n <= 0)
		return list;

	Item* copy = list;
	Item* copy2 = list;
	
	int len = 1;

	while (copy->next != NULL) { //conto la lunghezza della lista
		len++;
		copy = copy->next;
	}

	if (n >= len)
		n = n%len;

	if (n == 0)
		return list;

	copy = list;
	copy2 = list;

	//primo giro a parte
	Item* tmp = copy->next;
	copy->next = copy->next->next;
	tmp->next = list;
	list = tmp;

	copy = list;

	//scambi intermedi

	int n2;
	if (n < len - 1) n2 = n;
	else
		n2 = n - 1;

	for (int i = 1; i < n2; i++) {

		copy = list->next;
		copy2 = list; //mantiene precedente

		int j = 1;
		while (j < i) {
			copy = copy->next;
			copy2 = copy2->next;
			j++;
		}
			 //mi riporto sullo stesso nodo per spostarlo di nuovo

		Item* tmp = copy->next;
		copy->next = copy->next->next;
		tmp->next = copy;
		copy2->next = tmp;
	}

	//ultimo scambio se n = len - 1
	if (n == len - 1){
		copy = list->next;
		copy2 = list; //mantiene precedente

		int j = 1;
		while (j < n - 1) {
			copy = copy->next; //copy punta al penultimo, copy2 al terzultimo
			copy2 = copy2->next;
			j++;
		}

		copy->next->next = copy;
		copy2->next = copy->next;
		copy->next = NULL;
	}

	return list;

}


