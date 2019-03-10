#include <iostream>
using std::cout;
using std::endl;

int main()
{
	unsigned short points[] = { 82, 75, 39, 93, 2, 64, 28,74, 9, 46};
	unsigned short K = sizeof points / sizeof( points[0]);
	unsigned short i = 0, max, max2, p, p2;
	for (max = points[i++];i < K; i++)
	{
		if ( max < points[i])
		{
			max = points[i];
			p = i;
		}
	}

	for (max2 = 0,i = 0; i < K ; i++ )
	{
		if (max2 < points[i] && points[i] != max)
		{
			max2 = points[i];
			p2 = i;
		}
	}

	cout << p << '\t' << max << '\n' ;
	cout << p2<< '\t' << max2<< '\n' ;
	return 0;
}

