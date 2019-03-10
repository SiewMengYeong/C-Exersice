#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

class Circle
{
public:
double m_r;
double m_h;
double circlevolume();
};

double Circle::circlevolume()
{
return m_r*m_r*m_h;
}

int main()
{
Circle x={5,10};
Circle* y;
cout<<x.circlevolume()<<endl;
cout<<x.m_h<<endl;
y=&x;
cout<<(*y).m_h<<endl;
cout<<(*y).circlevolume()<<endl;
return 0;
}

