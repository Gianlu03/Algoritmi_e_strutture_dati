#include"colora.h"

void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, char* sequenzaColori, int* nsol, int i) {
	
	//se i arriva a superare l'ultimo elemento, allora ho trovato una soluzione, la conto e stampo
	if (i >= m->size) {
		*nsol += 1; //conto sol.
		for (int j = 0; j < m->size; j++) { //stampo sol
			if (j > 0)
				printf(" ");
			printf("%d -> %c;", j, sequenzaColori[j]);
		}
		printf("\n");
		return;
	}

	//caso generale
	for (int j = 0; j < c_size; j++) {
		sequenzaColori[i] = c[j]; //provo il colore
		bool nonValido = false;
		//controllo se gli elementi adiacenti hanno lo stesso colore
		for (int k = 0; k < m->size; k++) {
			if (k == i) //salto il confronto con se stesso
				continue;

			if (m->data[i*m->size + k] == 1 && sequenzaColori[k] == sequenzaColori[i]){ //Se l'area è vicina ed ha lo stesso colore poto il ramo
				nonValido = true;
			}
			
		}

		if (nonValido == true)
			continue; //salto la chiamata ricorsiva con questa combinazione
		
		MappaColoriRec(m, c, c_size, sequenzaColori, nsol, i + 1);
	}
	sequenzaColori[i] = 0; //resetto cella colore

}

int MappaColori(const struct Matrix* m, const char* c, size_t c_size){
	if (m == NULL || c == NULL || c_size == 0)
		return 0;

	char* sequenzaColori = calloc(m->size, sizeof(char));
	int nsol = 0;

	MappaColoriRec(m, c, c_size, sequenzaColori, &nsol, 0);

	free(sequenzaColori);

	return nsol;

}

/*
int main(void) {

	struct Matrix* m = malloc(sizeof(struct Matrix));
	m->size = 3;
	m->data = malloc(sizeof(bool) * m->size * m->size);

	m->data[0] = 1; m->data[1] = 1; m->data[2] = 1;
	m->data[3] = 1; m->data[4] = 1; m->data[5] = 0;
	m->data[6] = 1; m->data[7] = 0; m->data[8] = 1;

	char* c = "rv";
	size_t c_size = 2;

	int nsol = MappaColori(m, c, c_size);

}

*/