#include <iostream>
using std::cout;

int main()
{
	int even = 0, odd = 1;
	char str[] = "NETHERLANDS";
	for (int i = 0; i < 12 ; i++ )
		switch (str[i] % 2)
		{
			case 0:
				even++;
				break;
			case 1:
				odd++;
				break;
		}
	cout << "odd = " << odd << '\n' 
	     << "even = " << even << '\n' 
	     << str[11]%2<<'\n';
	return 0;
}

