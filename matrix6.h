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

CMatrix Transpose()
{
CMatrix c(m_Column,m_Row);
for (int i=0;i<m_Row;i++)
{
  for (int j=0;j<m_Column;j++)
    c.pentry[j*m_Row+i]=pentry[i * m_Column + j];
}
return c;
}

CMatrix Augment(CMatrix B)
{
CMatrix c(m_Row,m_Column+B.m_Column);
if (m_Row==B.m_Row)
{
for(int i=0;i<m_Row;i++)
{
  for (int j=0;j<m_Column;j++)
    c.Set(i,j,Get(i,j));
}
for(int i=0;i<m_Row;i++)
{
  for (int j=m_Column;j<m_Column+B.m_Column;j++)
    c.Set(i,j,B.Get(i,j-m_Column));
}
}
else
m_Row=m_Column=0;
return c;
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

CMatrix Identity(int n)
{
CMatrix x(n,n,0);
{
for (int i=0;i<n;i++)
  x.Set(i,i,1);
}
return x;
}
