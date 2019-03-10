#include <iostream>
using std::cout;

int main()
{
	int data[5] = {2 * 5};
	int i;
	for ( i=0 ; i < 5 ; i += 2)
		data[i] = i;
	for ( i=0 ; i < 5 ; i++)
		cout << data[i];
	return 0;
}

