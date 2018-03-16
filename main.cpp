#include <iostream>
#include "passeiocavalo.hpp"

using namespace std;

int main()
{
	c_map m;
	bool s;
	m.allocate(4, 10);
	s = m.horse_ride(4, 3);
	m.print_map();
	m.deallocate();
	
	if(s)
		cout << "solucao encontrada"<< endl;
	else
		cout << "sem solucao"<< endl;
	
	return 0;
}
