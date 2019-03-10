class CMatrix
{
public:
CMatrix(int n=0)
{
m_Column=n;
m_Row=n;
pentry=new int[n*n];
for (int i=0;i<n;i++)
{
  for (int j=0;j<n;j++)
    Set(i,j,0);
}
cout<<"Constructor called for a "<<n<<"*"<<n<<" matrix."<<endl;

cout<<(sizeof(m_Column))<<' '<<(sizeof(m_Row))<<' '<<(sizeof(pentry))<<endl;
}
CMatrix(int m, int n, int v = 0)
{
m_Column=m;
m_Row=n;
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
