#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NO {
	int dado;
	NO* prox;
}NO;

typedef struct FILA {
	NO* inicio;
	NO* fim;
} FILA;

FILA *f;

void enfileira(int valor){
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->dado = valor;
	ptr->prox = NULL;
	if(f->inicio == NULL){
		f->inicio = ptr;
	}
	else {
		f->fim->prox = ptr;
	}
	f->fim = ptr;
}

int desenfileira(){
	NO* ptr = f->inicio;
	int dado;
	if(ptr != NULL){
		f->inicio = ptr->prox;
		ptr->prox = NULL;
		dado = ptr->dado;
		free(ptr);
		return dado;
	}
}
void mostrar(NO* f){ //Recebe uma vari�vel f do tipo ponteiro de NO
	while(f->prox != NULL){ //Enquanto o NO n�o apontar para NULL, ou seja, n�o estiver no �ltimo elemento
		printf("%d\n", f->dado); //Imprime os dados dos elementos da fila
		f = f->prox; // A fila recebe o pr�ximo dado para imprimir na pr�xima repeti��o
	}
	printf("%d\n", f->dado); //Como o �ltimo elemento n�o vai ser impresso, � necess�rio essa impress�o

}


int main (){
	f = (FILA *) malloc(sizeof(FILA));
	f->inicio = NULL;
	f->fim = NULL;
	
	system("pause");
	
	printf("Enfileirando ... \n");
	enfileira(10);
	mostrar(f->inicio);
	system("pause");
	
	printf("Enfileirando ... \n");
	enfileira(30);
	mostrar(f->inicio);
	system("pause");
	
	printf("Enfileirando ... \n");
	enfileira(50);
	mostrar(f->inicio);
	system("pause");
	
	printf("Desenfileirando ... \n");
	desenfileira();//Retirou o primeiro elemento da fila, no caso o 10
	mostrar(f->inicio);
	system("pause");
	
	printf("Enfileirando ... \n");
	enfileira(14);
	mostrar(f->inicio);
	
	return(0);
}
