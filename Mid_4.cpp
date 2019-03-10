#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

int main()
{
	char name[][10] = { "Alice", "Bob", "Charlie", "Dennis", "Emily"};
	
	cout << sizeof(name) << endl;
	cout << sizeof(name[1]) << endl;
	cout << strlen(name[1]) << endl;
	cout << sizeof(name[1][2]) << endl;

	return 0; 
}

