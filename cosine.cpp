#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
  float x,y;
  int i,j;
  std::cout<<std::fixed;
  for (i=0;i<=360;i+=15)
   {
    x=i*M_PI/180;
    y=cos(x);
    std::cout<<std::setw(3)<<i<<'\t'
             <<std::setprecision(5)<<x<<'\t'
             <<std::setprecision(5)<<std::showpos<<y<<std::noshowpos;
    
    for (j=0;j<=(y*20)+25;j++)
      std::cout<<' ';
    std::cout<<'*'<<std::endl;
   }

}
