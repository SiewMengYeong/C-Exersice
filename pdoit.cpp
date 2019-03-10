# include <iostream>
using std::cout;
using std::endl;

long product(long a , long b)
{
return a*b;
}

long sum(long a , long b)
{
return a+b;
}

int main()
{
long (*pdoit)(long,long);
pdoit=sum;
cout<<pdoit(3,5)<<endl;
pdoit=product;
cout<<pdoit(3,5)<<endl;

long (*pfun[2])(long,long);
pfun[0]=sum;
pfun[1]=product;
cout<<pfun[0](3,5)<<endl;
cout<<pfun[1](3,5)<<endl;

return 0;
}
