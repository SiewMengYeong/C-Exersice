#include <iostream>
using std::cout;
using std::endl;

class CData
{
public:
    int* pdata;

    CData(int v = 0)
    { pdata = new int(v); }

     CData operator=(CData d)
    { 
      pdata = d.pdata;
      return CData( *d.pdata );
    }

    void Print()
    { cout << *pdata << endl; }
};

int main()
{
    CData a(5), b(3);
    CData c;
    c = a;
    a = b;
    c.Print();
    return 0;
}
