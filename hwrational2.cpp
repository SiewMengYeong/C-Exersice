#include <iostream>
using std::cout;
using std::endl;

struct rational
{
    int numerator;
    int denominator;
};

//typedef struct rational Rational;

rational add(rational a,rational b)
{
  rational c;
  c.numerator=a.numerator*b.denominator+a.denominator*b.numerator;
  c.denominator=a.denominator*b.denominator;
  for(int i=2;i<=c.numerator&&i<=c.denominator;i++)
  {
    if (c.numerator%i==0 && c.denominator%i==0)
    {
      c.numerator/=i;
      c.denominator/=i;
      i=2;
    }
  }
  return c;
}
void print(rational x)
{
  cout<<x.numerator<<'/'<<x.denominator;
  return;
}


int main()
{
    const unsigned short N = 5;
    rational a[N]   = { {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5} };
    rational b[N] = { {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} };
    rational c[N];
    int i;
    for (i=0; i<N; i++)
    {
        c[i]=add(a[i], b[i]);
        print(a[i]);
        cout << " + ";
        print(b[i]);
        cout << " = ";
        print(c[i]);
        cout << endl;
    }
    return 0;
}
