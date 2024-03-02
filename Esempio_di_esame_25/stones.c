#define _CRT_SECURE_NO_WARNINGS

#include"maxheap.h"

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<stdint.h>

void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}

extern int LastStoneWeight(Heap* h) {

    if (h == NULL || HeapIsEmpty(h) || h->size == 0)
        return 0;

    ElemType p1, p2;

    while (h->size > 1) {
        Pop(h, &p1);
        Pop(h, &p2); //prendo le 2 pietre più pesanti (p1 >= p2 dato che è maxheap)

        if (ElemCompare(&p1, &p2) != 0) {
            ElemType pRes = p1 - p2;
            HeapMaxInsertNode(h, &pRes); //il mattone risultante lo rimetto nel mucchio
        }
        //se uguali non faccio niente, quindi ho tolto entrambi i mattoni tramite pop
    }

    if (h->size == 1) {
        return (int)h->data[0];
    }
    
    if (h->size == 0)
        return 0;

}

