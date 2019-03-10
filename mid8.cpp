#include <iostream>
using std::cout;
using std::endl;

int main()
{
  const int N = 3;
  int a[N][N] = { 0 };
  int i = 0, j = N / 2;

  for (int k=1; k <= N * N; k++)
  {
     a[i][j] = k;
     if ( ( i>0 && j<N-1 && a[i-1][j+1] > 0) || (i==0 && j==N-1) )
     {
        ++i; 
        cout<<"++i"<<endl;
     }
     else
     {
        if (++j >= N) {j = 0;cout<<"j=0"<<endl;}
        if (--i <  0) {i = N-1;cout<<"i=N-1"<<endl;}
     }
     cout<<"k="<<k<<endl<<endl;
  }
  
      
  for (i=0; i<N; i++)
  {
    for (j=0; j<N; j++)
      cout << a[i][j];
    cout << endl;
  }
    return 0;
}
