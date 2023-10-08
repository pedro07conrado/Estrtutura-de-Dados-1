
all:
	# Compilando a implementacao do TAD
	gcc -c tad_vetor.c -o tad_vetor.o

	# Compilando o executavel
	gcc main.c tad_vetor.o -o main

	# Executando
	./main

clear:
	rm *.o
	rm main
