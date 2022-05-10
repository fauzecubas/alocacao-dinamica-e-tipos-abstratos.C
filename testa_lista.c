#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

int main () {
	lista_t* l = lista_cria();
	
	printf("-------ESTE É O PROGRAMA PARA TESTAR O FUNCIONAMENTO DE LISTAS!-------\n");
	printf("---------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------\n");
	
	printf("ESTA É A LISTA DE COMANDOS:\n");
	printf("1 - Inserir um elemento no início da lista.\n");
	printf("2 - Inserir um elemento no fim da lista.\n");
	printf("3 - Inserir um elemento de forma ordenada.\n");
	printf("4 - Retirar o elemento do inicio da lista.\n");
	printf("5 - Retirar o elemento do final da lista.\n");
	printf("6 - Retirar um elemento de sua escolha da lista.\n");
	printf("7 - Saber se um elemento pertence à lista.\n");
	printf("8 - Saber o tamanho da lista.\n");
	printf("9 - Saber se a lista é vazia.\n");
	printf("Outro número - Parar a execução do programa :(.\n");
	printf("---------------------------------------------------------------------\n");
	
	printf("Qual comando executar a seguir?\n");
	int comando;
	scanf("%d", &comando);
	while (comando != 10) {
		int imprimirLista = 0;
		if (comando == 1) {
			printf("Número que deseja inserir: ");
			int entrada;
			scanf("%d", &entrada);
			lista_insere_inicio(l, entrada);
			imprimirLista = 1;
		} else if (comando == 2) {
			printf("Número que deseja inserir: ");
			int entrada;
			scanf("%d", &entrada);
			lista_insere_fim(l, entrada);
			imprimirLista = 1;
		} else if (comando == 3) {
			printf("Número que deseja inserir: ");
			int entrada;
			scanf("%d", &entrada);
			lista_insere_ordenado(l, entrada);
			imprimirLista = 1;
		} else if (comando == 4) {
			int entrada;
			int r = lista_retira_inicio(l, &entrada);
			if (!r) {
				printf("Lista ainda vazia!\n");
			} else {
				imprimirLista = 1;
			}
		} else if (comando == 5) {
			int entrada;
			int r = lista_retira_fim(l, &entrada);
			if (!r) {
				printf("Lista ainda vazia!\n");
			} else {
				imprimirLista = 1;
			}
		} else if (comando == 6) {
			if (lista_vazia(l)) {
				printf("Lista ainda vazia!\n");
			} else {
				printf("Número que deseja retirar: ");
				int entrada;
				scanf("%d", &entrada);
				int r = lista_retira_elemento(l, &entrada);
				if (!r) {
					printf("Elemento não encontrado!\n");
				} else {
					imprimirLista = 1;
				}
			}
		} else if (comando == 7) {
			if (lista_vazia(l)) {
				printf("Lista ainda vazia!\n");
			} else {
				printf("Número que deseja procurar: ");
				int entrada;
				scanf("%d", &entrada);
				if (lista_pertence(l, entrada)) {
					printf("O elemento %d pertence à lista!\n", entrada);
				} else {
					printf("O elemento %d NÃO pertence à lista!\n", entrada);
				}
			}
		} else if (comando == 8) {
			printf("Tamanho da lista: %d.\n", lista_tamanho(l));
		} else if (comando == 9) {
			if (lista_vazia(l)) {
				printf("Lista vazia.\n");
			} else {
				printf("Lista NÃO vazia.\n");
			}
		} else {
			break;
		}
		
		if (imprimirLista) {
			if (lista_vazia(l)) {
				printf("Lista agora vazia...\n");
			} else {
				printf("LISTA ATUALIZADA: ");
				lista_imprime(l);
			}
		}
		
		printf("Qual comando executar a seguir?\n");
		scanf("%d", &comando);
	}
	
	l = lista_destroi(l);


        return 0;
}
