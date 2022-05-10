#include <stdio.h>
#include <stdlib.h>
#include "libpilha.h"

int main () {
	printf("-------ESTE É O PROGRAMA PARA TESTAR O FUNCIONAMENTO DE PILHAS!-------\n");
	printf("---------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------\n");
	
	printf("Qual será o tamanho da pilha?\n");
	int tam;
	scanf("%d", &tam);
	pilha_t* p = pilha_cria(tam);
	
	printf("ESTA É A LISTA DE COMANDOS:\n");
	printf("1 - Inserir um elemento na pilha.\n");
	printf("2 - Retirar um elemento da pilha.\n");
	printf("3 - Saber o topo da pilha.\n");
	printf("4 - Saber o tamanho da pilha.\n");
	printf("5 - Saber se a pilha está vazia.\n");
	printf("6 - Imprimir a pilha.\n");
	printf("Outro número - Parar a execução do programa :(.\n");
	printf("---------------------------------------------------------------------\n");
	
	printf("Qual comando executar a seguir?\n");
	int comando;
	scanf("%d", &comando);
	while (comando != 7) {
		int imprimirPilha = 0;
		if (comando == 1) {
			printf("Número que deseja inserir: ");
			int entrada;
			scanf("%d", &entrada);
			int x = push(p, entrada);
			if (x == -1) {
				printf("Ops, pilha cheia!\n");
			} else {
				imprimirPilha = 1;
			}
		} else if (comando == 2) {
			if (pilha_vazia(p)) {
				printf("Pilha vazia.\n");
			} else {
				pop(p);
				imprimirPilha = 1;
			}
		} else if (comando == 3) {
			if (pilha_vazia(p)) {
				printf("Pilha vazia.\n");
			} else {
				printf("Topo da pilha: %d\n", pilha_topo(p));
			}
		} else if (comando == 4) {
			printf("Tamanho da pilha: %d.\n", pilha_tamanho(p));
		} else if (comando == 5) {
			if (pilha_vazia(p)) {
				printf("A pilha é vazia!\n");
			} else {
				printf("A pilha NÃO é vazia!\n");
			}
		} else if (comando == 6) {
			if (pilha_vazia(p)) {
				printf("A pilha é vazia!\n");
			} else {
				printf("Pilha: ");
				pilha_imprime(p);
			}
		} else {
			break;
		}
		
		
		if (imprimirPilha) {
			if (pilha_vazia(p)) {
				printf("Pilha agora vazia!\n");
			} else {
				printf("PILHA ATUALIZADA: ");
				pilha_imprime(p);		
			}
		}
		
		printf("Qual comando executar a seguir?\n");
		scanf("%d", &comando);
	}

	p = pilha_destroi(p);

        return 0;
}
