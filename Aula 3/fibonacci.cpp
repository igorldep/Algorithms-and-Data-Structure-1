#include <iostream>

using namespace std;

int fib(int n);

int main()
{
	int n;
	int num;
	
	cin >> n;
	
	num = fib(n);
		
	cout << num << endl;
	
	return 0;
}

int fib(int n){
	if(n == 0 || n == 1)
		return 1;
	else
		return fib(n-1) + fib (n-2);
}