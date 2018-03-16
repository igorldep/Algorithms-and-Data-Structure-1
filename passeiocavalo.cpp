#include "passeiocavalo.hpp"


//construtor
c_map::c_map():map(nullptr),nrows(0),ncols(0)
{	// registra a possibilidade do cavalo partindo de um ponto de partida incial 
	//+1 na coluna, +2 na linha
	possible_moves[0][0] = 1;
	possible_moves[0][1] = 2;
	
	//+2 na coluna, +1 na linha
	possible_moves[1][0] = 2;
	possible_moves[1][1] = 1;
	
	//+2 na coluna, -1 na linha
	possible_moves[2][0] = 2;
	possible_moves[2][1] =-1;
	
	//+1 na coluna, -2 na linha
	possible_moves[3][0] = 1;
	possible_moves[3][1] =-2;
	
	//-1 na coluna, -2 na linha
	possible_moves[4][0] =-1;
	possible_moves[4][1] =-2;
	
	//-2 na coluna, -1 na linha
	possible_moves[5][0] =-2;
	possible_moves[5][1] =-1;
	
	//-2 na coluna, +1 na linha
	possible_moves[6][0] =-2;
	possible_moves[6][1] = 1;
	
	//-1 na coluna, +2 na linha
	possible_moves[7][0] =-1;
	possible_moves[7][1] = 2;
}

//destrutor
c_map::~c_map(){ deallocate(); }

//alocado?
bool c_map::is_allocated(){ return map != nullptr; }

//aloca e marca as posicoes como nao visitadas
void c_map::allocate(int num_rows, int num_cols)
{
	if(is_allocated())
		deallocate();
	
	nrows = num_rows;
	ncols = num_cols;
	
	map = new int*[nrows];
	for(int i = 0; i < nrows; i++)
	{
		map[i] = new int[ncols];
		for(int j = 0; j < ncols; j++)
			map[i][j] = 0;
	}
}

//desaloca
void c_map::deallocate()
{
	if(is_allocated())
	{
		for(int i = 0; i < nrows; i++)
			delete[] map[i];
		delete[] map;
		map = nullptr;
	}
}

//tenta inserir um valor em uma posicao do mapa
bool c_map::play(int col, int row, int value)
{
	//se a posicao esta fora do mapa
	if(col < 0 || col >= ncols || row < 0 || row >= nrows) return false;
	
	//se a posicao nao foi visitada
	if(map[row][col] == 0)
	{
		map[row][col] = value;
		return true;
	}
	else return false;
}

//desfaz jogada
void c_map::undo_play(int col, int row)
{
	map[row][col] = 0;
}

//imprime matriz
void c_map::print_map()
{
	cout << endl;
	for(int i = 0; i < nrows; i++)
	{
		for(int j = 0; j < ncols; j++)
			cout << setw(3) << map[i][j] << ' ';
		cout << endl;
	}
}

//passeio do cavalo
bool c_map::horse_ride(int col, int row)
{
	int move_id = 1;
	bool success = false;
	
	map[row][col] = move_id;
	try_move(move_id+1, col, row, success);
	
	print_map();

	return success;
}

void c_map::try_move(int move_id, int col, int row, bool &success)
{
	int next_col, next_row;
	bool success_move = false;
	
	//8 tentativas possiveis
	for(int t_id = 0; t_id < 8 && !success_move; t_id++)
	{
		next_col = col + possible_moves[t_id][0];
		next_row = row + possible_moves[t_id][1];
		
		if(play(next_col, next_row, move_id))
		{
			if(move_id < ncols*nrows)
			{
				try_move(move_id+1, next_col, next_row, success_move);
				if(!success_move)
					undo_play(next_col, next_row);
			}
			else
				success_move = true;
		}
	}
	success = success_move;
}

//***********************//

void try_move(c_map &map, int move_id, int col, int row, bool &success)
{
	int next_col, next_row;
	bool success_move = false;
	
	//8 tentativas possiveis
	for(int t_id = 0; t_id < 8 && !success_move; t_id++)
	{
		next_col = col + map.possible_moves[t_id][0];
		next_row = row + map.possible_moves[t_id][1];
		
		if(map.play(next_col, next_row, move_id))
		{
			if(move_id < map.ncols*map.nrows)
			{
				try_move(map, move_id+1, next_col, next_row, success_move);
				if(!success_move)
					map.undo_play(next_col, next_row);
			}
			else
				success_move = true;
			map.print_map();
		}
	}
	success = success_move;
}
