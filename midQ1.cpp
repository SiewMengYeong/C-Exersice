#include <iostream>
using std::cout;
using std::endl;

int bin2dec(char x[])
{
int y=0;
for(int i=strlen(x)-1;i>=0;i--)
{
  int z=1;
  for(int j=1;j<strlen(x)-i;j++)
  {
    z*=2;
  }
  y+=((x[i]-'0')*z);
}
return y;
}

int main()
    {
	cout << bin2dec("11") << endl
	     << bin2dec("100") << endl
	     << bin2dec("1111") << endl
	     << bin2dec("1010") << endl;
	return 0;
    }
