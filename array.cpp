#include <iostream>
#include <iomanip>

int main()
{
int a[3][3]={};
for (int i(0);i<3;i++)
{
  for(int j(0);j<3;j++)
    std::cout<<std::setw(4)<<a[i][j];
  std::cout<<std::endl;
}
return 0;
}
