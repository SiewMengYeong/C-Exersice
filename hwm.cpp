#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int i,x,y,z,e(0);
  srand((unsigned)time(NULL));
  unsigned int t1,t2;
  t1=time(NULL);
  for (i=1;i<=10;i++)
  {
    x=rand()%100;
    y=rand()%100;
    cout<<x<<"*"<<y<<"=";
    cin>>z;
    if (z!=x*y)
    {
      cout<<"Wrong! "<<x<<"*"<<y<<"="<<x*y<<endl;
      e++;
    }
  }
  t2=time(NULL);
  cout<<"You made "<<e<<" mistake"<<(e>1?"s ":" ")<<"today."<<endl;
  cout<<"You use "<<t2-t1<<" seconds."<<endl;
  return 0;

}
