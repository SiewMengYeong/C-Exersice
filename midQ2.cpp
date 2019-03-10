#include <iostream>
using std::cout;
using std::endl;

int hex2dec(const char x[])
{
int y=0;
for(int i=strlen(x)-1;i>=0;i--)
{
  int z=1;
  for(int j=1;j<strlen(x)-i;j++)
  {
    z*=16;
  }
  if (x[i]>='0'&&x[i]<='9')
    y+=((x[i]-'0')*z);
  else
    y+=((x[i]-'A'+10)*z);
}
return y;
}

int main()
    {
	cout << hex2dec("9") << endl
	     << hex2dec("F") << endl
	     << hex2dec("20") << endl
	     << hex2dec("FF") << endl;
	return 0;
    }
