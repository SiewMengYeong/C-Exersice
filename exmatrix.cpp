#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

int main()
{
const int N=3;
const int a[N][N]={ {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                  };
const int b[N][N]={ {1, 4, 7},
                    {2, 5, 8},
                    {3, 6, 9}
                  };
int c[N][N]={0};

for (int i=0;i<N;i++)
{
  for (int j=0;j<N;j++)
  {
    for (int k=0;k<N;k++)
      c[i][j]+=a[i][k]*b[k][j];
  }
}

for (int i=0;i<N;i++)
{
  for (int j=0;j<N;j++)
  {
    cout<<std::setw(4)<<c[i][j];
  }
  cout<<endl;
}
return 0;
}

