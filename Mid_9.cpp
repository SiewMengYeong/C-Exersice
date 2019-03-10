#include <iostream>
using std::cout;
using std::endl;

int main()
{
	char ciphertext[] = "NOGPQROHNG";
	char password[] = "NETHERLANDS";
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char mapping[26];
	char reverse[26];
	char c;
	unsigned short i, j, k;

	for (k=0, i=0; (c = password[i]) != '\0'; i++ )
	{
		if (alphabet[c - 'A'] != 0)
		{
			mapping[k++] = c;
			alphabet[c - 'A'] = 0;
		}
	}

	for (j=0; k < 26;)
	{
		while (alphabet[j] == 0) j ++;
		mapping[k++] = alphabet[j++];
	}

	for ( i=0; i < 26; i++)
		reverse[mapping[i] - 'A'] = 'A' + i;
	
	for ( i=0; (c = ciphertext[i]) != '\0';i++)
		cout << reverse [c - 'A'];
	cout << endl;

	return 0;
}


