#include <stdio.h>
#include <stdlib.h>
#include "libfila.h"

int main () {
	fila_t* f = fila_cria();
	
	printf("-------ESTE É O PROGRAMA PARA TESTAR O FUNCIONAMENTO DE FILAS!-------\n");
	printf("---------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------\n");
	
	printf("ESTA É A LISTA DE COMANDOS:\n");
	printf("1 - Inserir um elemento na fila.\n");
	printf("2 - Remover um elemento da fila.\n");
	printf("3 - Saber o tamanho da fila.\n");
	printf("4 - Saber se a fila é vazia.\n");
	printf("Outro número - Parar a execução do programa :(.\n");
	
	printf("---------------------------------------------------------------------\n");
	
	printf("Qual comando executar a seguir?\n");
	int comando;
	scanf("%d", &comando);
	while (comando != 5) {
		int imprimirFila = 0;
		if (comando == 1) {
			printf("Número que deseja inserir: ");
			int entrada;
			scanf("%d", &entrada);
			queue(f, entrada);
			imprimirFila = 1;
		} else if (comando == 2) {
			int elementoRetirado;
			int x = dequeue(f, &elementoRetirado);
			if (x) {
				imprimirFila = 1;
			} else {
				printf("Fila vazia!\n");
			}
		} else if (comando == 3) {
			printf("Tamanho da fila: %d\n", fila_tamanho(f));
		} else if (comando == 4) {
			if (fila_vazia(f)) {
				printf("A fila é vazia!\n");
			} else {
				printf("A fila NÃO é vazia!\n");
			}
		} else {
			break;
		}
		
		if (imprimirFila) {
			if (fila_vazia(f)) {
				printf("Fila agora vazia...\n");
			} else {
				printf("FILA ATUALIZADA: ");
				fila_imprime(f);
			}		
		}
		
		printf("Qual comando executar a seguir?\n");
		scanf("%d", &comando);
	}
	
	f = fila_destroi(f);
	
	return 0;
}
