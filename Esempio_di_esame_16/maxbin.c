#define _CRT_SECURE_NO_WARNINGS

#include"tree.h"

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

Node* CreateMaxBinTreeRec(const ElemType* v, size_t v_size, size_t start, size_t end) {
	ElemType max = v[start];
	int indexMax = start;
	if (start < end- 1) { //se start e end coincidono ho già il massimo
		for (int i = start + 1; i < end; i++)
			if (ElemCompare(&max, v + i) == -1) //se il massimo è minore lo aggiorno
			{
				max = ElemCopy(v + i);
				indexMax = i;
			}
	}
	else  //se rimane un singolo elemento costruisco radice con figli nulli
		return TreeCreateRoot(&max,
			NULL,
			NULL  //ramo destro, parte destra al massimo
		);


	if (indexMax == start) //costruisco solo a destra
		return TreeCreateRoot(&max,
			NULL,
			CreateMaxBinTreeRec(v, v_size, indexMax + 1, end)  //ramo destro, parte destra al massimo
		);

	else if (indexMax == end - 1) //costruisco solo a sinistra
		return TreeCreateRoot(&max,
			CreateMaxBinTreeRec(v, v_size, start, indexMax),
			NULL  //ramo destro, parte destra al massimo
		);

	else 		//costruisco entrambi i rami
		return TreeCreateRoot(&max,
			CreateMaxBinTreeRec(v, v_size, start, indexMax), //ramo sinistro, parte sinistra al massimo
			CreateMaxBinTreeRec(v, v_size, indexMax + 1, end)  //ramo destro, parte destra al massimo
		);



}


Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0)
		return TreeCreateEmpty();

	return CreateMaxBinTreeRec(v, v_size, 0, v_size);

}


/*
int main(void) {

	ElemType v[] = { 0, 4, 45, 12, 7, 88, 3, 52, 2, 78, 35, 11 };
	Node* tree = CreateMaxBinTree(v, 12);
	return 0;
}
*/