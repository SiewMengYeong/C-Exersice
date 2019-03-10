#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;

class CMatrix
{
public:
CMatrix(int n=0)
{
m_Row=n;
m_Column=n;
pentry=new int[n*n];
for (int i=0;i<n;i++)
{
  for (int j=0;j<n;j++)
    Set(i,j,0);
}
cout<<"Constructor called for a "<<n<<"*"<<n<<" matrix."<<endl;
}

CMatrix(int m, int n, int v = 0)
{
m_Row=m;
m_Column=n;
pentry=new int[m*n];
for (int i=0;i<m;i++)
{
  for (int j=0;j<n;j++)
    Set(i,j,v);
}
cout<<"Constructor called for a "<<m<<"*"<<n<<" matrix."<<endl;
}

~CMatrix()
{
cout<<"Destructor called for a "<<m_Row<<"*"<<m_Column<<" matrix."<<endl;
delete[] pentry;
}

int Get(int i,int j)
{
if( 0<=i && i<=m_Row && 0<=j && j<=m_Column)
return pentry[i * m_Column + j];
}

void Set(int i,int j,int n)
{
pentry[i * m_Column + j]=n;
}

void Print()
{
int x;
if (MaxEntry()>=0 && MaxEntry()<10)
  x=2;
if (MaxEntry()>=10 && MaxEntry()<100)
  x=3;
if (MaxEntry()>=100)
  x=4;

for (int i=0;i<m_Row;i++)
{
  for (int j=0;j<m_Column;j++)
    cout<<setw(x)<<Get(i,j)<<setw(x);
  cout<<endl;
}
}

int MaxEntry()
{
int x=0;
for (int i=0;i<m_Row;i++)
{
  for (int j=0;j<m_Column;j++)
{
    if (Get(i,j)>=x)
      x=Get(i,j);
    if (-Get(i,j)>=x)
      x=-Get(i,j);
}
}
return x;
}

unsigned short Row()
{
return m_Row;
}

unsigned short Column()
{
return m_Column;
}

CMatrix Add(CMatrix x)
{
CMatrix c(m_Row,m_Column);
if (m_Row==x.m_Row && m_Column==x.m_Column)
{
for (int i=0;i<m_Row;i++)
{
  for (int j=0;j<m_Column;j++)
  {
    c.pentry[i * m_Column + j]=pentry[i * m_Column + j]+x.pentry[i * m_Column + j];
  }
}
}

else
c.m_Row=c.m_Column=0;

return c;
}

CMatrix operator+(const CMatrix& c)
{
  return Add(c);
}

CMatrix Subtraction(CMatrix x)
{
CMatrix c(m_Row,m_Column);
if (m_Row==x.m_Row && m_Column==x.m_Column)
{
for (int i=0;i<m_Row;i++)
{
  for (int j=0;j<m_Column;j++)
  {
    c.pentry[i * m_Column + j]=pentry[i * m_Column + j]-x.pentry[i * m_Column + j];
  }
}
}

else
c.m_Row=c.m_Column=0;

return c;
}

CMatrix operator-(const CMatrix& c)
{
  return Subtraction(c);
}



private:
unsigned short m_Row;
unsigned short m_Column;
int* pentry;

public:
CMatrix(const CMatrix& x)
{
m_Row=x.m_Row;
m_Column=x.m_Column;
pentry=new int[m_Row*m_Column];
for (int i=0;i<m_Row;i++)
{
  for (int j=0;j<m_Column;j++)
  pentry[i * m_Column + j]=x.pentry[i * m_Column + j];
}    

cout<<"Copy constructor called for a "<<m_Row<<"*"<<m_Column<<" matrix."<<endl;
}

};



int main()
{
    CMatrix a(3,4,1);
    CMatrix b(3,4,2);
    CMatrix d(3,4,4);

    a.Set(1,1,10);
    b.Set(2,2,100);

    CMatrix c = a-b-d;
    c.Print();

    return 0;
}


