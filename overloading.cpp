# include <iostream>
using std::cout;
using std::endl;

void display(char x[])
{
cout<<x<<endl;
for (int i=0;i<14;i++)
  cout<<'=';
cout<<endl;
return;
}

void display(char x[],char y[])
{
cout<<x<<endl;
cout<<y<<endl;

for (int i=0;i<14;i++)
  cout<<'=';
cout<<endl;
return;
}

int main()
{
   char first[] = "C programming";
   char second[] = "is interesting";
 
   display(first);
   display(first, second);
 
   return 0;
}
