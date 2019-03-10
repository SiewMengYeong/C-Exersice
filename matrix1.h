class CMatrix
{
public:
CMatrix(int x=0)
{
for (int i=0;i<3;i++)
{
  for (int j=0;j<3;j++)
    entry[i][j]=x;
}
}

CMatrix()
{
for (int i=0;i<3;i++)
{
  for (int j=0;j<3;j++)
    entry[i][j]=0;
}
}

int Get(int i,int j)
{
if( 0<=i && i<=2 && 0<=j && j<=2)
return entry[i][j];
}

void Set(int i,int j,int n)
{
entry[i][j]=n;
}

void Print()
{
for (int i=0;i<3;i++)
{
  for (int j=0;j<3;j++)
    std::cout<<entry[i][j]<<'\t';
  std::cout<<endl;
}
std::cout<<endl;
}

private:
unsigned short m_Row;
unsigned short m_Column;
int entry[3][3];

};
