class CMatrix
{
public:
CMatrix(int x=0)
{
m_Column=3;
m_Row=3;
for (int i=0;i<3;i++)
{
  for (int j=0;j<3;j++)
    Set(i,j,x);
}
}

int Get(int i,int j)
{
if( 0<=i && i<=2 && 0<=j && j<=2)
return entry[i * m_Column + j];
}

void Set(int i,int j,int n)
{
entry[i * m_Column + j]=n;
}

void Print()
{
for (int i=0;i<3;i++)
{
  for (int j=0;j<3;j++)
    std::cout<<Get(i,j)<<'\t';
  std::cout<<endl;
}
std::cout<<endl;
}


CMatrix Add(CMatrix x)
{
CMatrix c;
for (int i=0;i<3;i++)
{
  for (int j=0;j<3;j++)
    c.entry[i * m_Column + j]=entry[i * m_Column + j]+x.entry[i * m_Column + j];
}
return c;
}


private:
unsigned short m_Row;
unsigned short m_Column;
int entry[3*3];

public:
CMatrix(const CMatrix& x)
{
m_Row=x.m_Row;
m_Column=x.m_Column;
for (int i=0;i<3;i++)
{
  for (int j=0;j<3;j++)
    entry[i * m_Column + j]=x.entry[i * m_Column + j];
}
}

};
