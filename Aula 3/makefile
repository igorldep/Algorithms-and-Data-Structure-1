SOURCE = fibonacci

all: compila linkedita executa

compila:
	g++ $(SOURCE).cpp -c -Wall -std=c++11 -g

linkedita:
	g++ $(SOURCE).o -o $(SOURCE)

executa:
	./$(SOURCE)

executa-passo:
	gdb $(SOURCE)

limpa:
	rm -f $(SOURCE).o $(SOURCE)
