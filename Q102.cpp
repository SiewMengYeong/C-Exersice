#include <iostream> 
using std::cout;
using std::endl;

class CData
{
public:
int* pdata;

CData(int v=0)
{pdata=new int(v);}

void operator=(CData d)
{
pdata=d.pdata;
}

void print()
{cout<<*pdata<<endl;}

};

int main()
{
CData a(10),b(5);
CData c;
c=a;
c.print();
return 0;
}
