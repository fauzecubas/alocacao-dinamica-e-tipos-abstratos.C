all: 
	gcc -c libfila.c -o libfila.o
	gcc -c liblista.c -o liblista.o
	gcc -c libpilha.c -o libpilha.o
	
	gcc -Wall -std=c90 libfila.o testa_fila.c -o testa_fila
	gcc -Wall -std=c90 liblista.o testa_lista.c -o testa_lista
	gcc -Wall -std=c90 libpilha.o testa_pilha.c -o testa_pilha
	
clean:
	rm -f *.o *.gch
