#include <iostream>
using std::cout;
using std::endl;

void add(int a1,int a2,int b1,int b2,int &c1,int &c2)
{
  c1=a1*b2+a2*b1;
  c2=a2*b2;
  for(int i=2;i<=c1&&i<=c2;i++)
  {
    if (c1%i==0 && c2%i==0)
    {
      c1/=i;
      c2/=i;
      i=2;
    }
  }
  return;
}
void print(int x,int y)
{
  cout<<x<<'/'<<y;
  return;
}

int main()
{
    const unsigned short N = 5;
    int a_numerator[N]   = { 1, 1, 1, 1, 1 };
    int a_denominator[N] = { 1, 2, 3, 4, 5 };
    int b_numerator[N]   = { 1, 2, 3, 4, 5 };
    int b_denominator[N] = { 1, 1, 1, 1, 1 };
    int c_numerator[N];
    int c_denominator[N];
    int i;
    for (i=0; i<N; i++)
    {
        add(a_numerator[i], a_denominator[i],
               b_numerator[i], b_denominator[i],
               c_numerator[i], c_denominator[i]);
        print(a_numerator[i], a_denominator[i]);
        cout << " + ";
        print(b_numerator[i], b_denominator[i]);
        cout << " = ";
        print(c_numerator[i], c_denominator[i]);
        cout << endl;
    }
    return 0;
}  
  
  
