
all:
	g++ -g -std=c++11 -Wall -fmax-errors=1 -c passeiocavalo.cpp
	g++ -g -std=c++11 -Wall -fmax-errors=1 -c main.cpp
	g++ -g -std=c++11 -o cavalo *.o

executa:
	./cavalo

limpa:
	rm cavalo *.o -f
