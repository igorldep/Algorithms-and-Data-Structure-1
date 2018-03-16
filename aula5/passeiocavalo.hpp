#ifndef PASSEIOCAVALO_H // if definido 
#define PASSEIOCAVALO_H

#include <iostream>
#include <iomanip> //formatar a saída - número fixos da casas decimais, reservar espaço para imprimir inteiro

using namespace std;

class c_map //criação de classe
{
public: //all public
	int ** map; //ponteiro duplo -> matriz
	int nrows, ncols;
	int possible_moves[8][2];
	
	c_map();
	~c_map();
	
	bool is_allocated();
	void allocate(int num_rows, int num_cols);
	
	//desaloca
	void deallocate();
	
	//tenta inserir um valor em uma posicao do mapa
	bool play(int col, int row, int value);
	
	//desfaz jogada
	void undo_play(int col, int row);
	
	//passeio do cavalo
	bool horse_ride(int col, int row);
	
	//tenta movimento
	void try_move(int move_id, int col, int row, bool &success);
	
	//imprime matriz
	void print_map();
};

//***********************//

void try_move(c_map &map, int move_id, int col, int row, bool &success);

#endif //fecha iff
