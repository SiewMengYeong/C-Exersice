#include <iostream>
using std::cout;

int main()
{
	int even = 0, odd = 0;
	char str[] = "Singapore";
	for (int i = 0; i < strlen(str) ; i++ )
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
	     << "even = " << even << '\n'; 
	return 0;
}

