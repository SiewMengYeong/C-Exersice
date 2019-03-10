#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
int main()
{
	const unsigned short N = 4;
	char matrix[N * N + 1];
	char plaintext[] = "Uiorknrsred a eCraopi oumtpler loA.tuoA.tuoA.tuo";

	char ciphertext[ sizeof(plaintext)];
	char *p = plaintext;
	unsigned i, j;

	while ( p < plaintext + strlen(plaintext))
	{
	for (i=0 ; i < N; i++)
		for (j = 0; j < N; j++)
		{
			matrix[i*N + j] = *p ? *p : 'A';
			++p;
		}

	for (j=0 ; j < N; j++)
		for (i=0; i < N; i++)
			cout << matrix[i*N + j];
	}
	cout << endl;
	return 0;
}


