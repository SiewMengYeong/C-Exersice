#include <iostream>
using std::cout;
using std::endl;

int main()
{
	const int K = 5;
	int count = 0;
	int i, j;
	for (i = 0; i < K; i++)
		for (j = 0; j < K; j++)
		{
			++count;
			if (i == j) break;
		}
	cout << count << endl;
	return 0;

}


