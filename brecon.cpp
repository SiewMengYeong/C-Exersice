#include <iostream>
int main()
{
  int i,x(1),y(1);
  for (i=0;i<10;i++)
  {
    if (i*x==5)
      break;

    std::cout<<i<<std::endl;

//   if (i==4)
//     break;
  }
  std::cout<<"_________"<<std::endl;
  return 0;

}
