#include <iostream>
#include <ctime>

int main()
{
  int i,a,b,c,e(0);
  unsigned int t1,t2;
  srand((unsigned)time(NULL));
  t1=time(NULL);
  for (i=0;i<10;i++)
  {
    for(c=101;c>100;)
    {
      a=rand()%100;
      b=rand()%100;
      c=a+b;
    }
    std::cout<<a<<"+"<<b<<"=";
    std::cin>>c;
    if (c!=a+b)
    {
      std::cout<<"Wrong! "<<a<<"+"<<b<<"="<<a+b<<std::endl;
      e++;
    }
  }
  t2=time(NULL);
  std::cout<<"You made "<<e<<" mistake"<<(e>1?"s ":" ")<<"today."
           <<std::endl;
  std::cout<<"You use "<<t2-t1<<" seconds."<<std::endl;
  return 0;
}
