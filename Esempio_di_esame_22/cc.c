#include "cc.h"

bool isIn(ElemType e, ElemType *v, size_t v_size) {
	for (int i = 0; i < v_size; i++)
		if (ElemCompare(&e, v+i) == 0)
			return true;
	return false;
}

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (i == NULL || v == NULL || v_size == 0)
		return 0;
	
	Item* l = i;
	int counter = 0;

	while (l->next != NULL) {
		
		if (isIn(l->value, v, v_size)) { //primo presente trovato
			counter++;
			while (l->next != NULL) {
				l = l->next;
				if (!isIn(l->value, v, v_size)) //fermo quando trovo uno non presente che spezza la componente
					break;
			}
		}

		if (!isIn(l->value, v, v_size) && l->next != NULL && l->next->next == NULL && isIn(l->next->value, v, v_size)) {
			return counter+1;
		}

		if (l->next != NULL)
			l = l->next;


	}

	return counter;

}

