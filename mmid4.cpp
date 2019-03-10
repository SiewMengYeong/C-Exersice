#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

int main()
{
	char str[] = "National Chi Nan University";
        cout << sizeof(str) << '\t'
             << strlen(str) << endl;

	str[8]='\0';
	cout << sizeof(str) << '\t'
	     << strlen(str) << endl;
	return 0; 
}

