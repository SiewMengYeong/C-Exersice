#include <iostream>
using std::cout;
using std::endl;

int main()
{
	const int N = 3;
	int a[N][N] = { 0 };
	int i = 0, j = N/2;
	for (int k = 1; k <= N * N; k++)
	{
		a[i][j] = k;
		if( ( i > 0 && j < N - 1 && a[i - 1][j + 1] > 0 ) || (i == 0 && j == N - 1) )
			++i;
		else
		{
			if ( ++j >= N ) j = 0;
			if ( --i <  0 ) i = N - 1;
		}
	}

	for ( i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}		

	

