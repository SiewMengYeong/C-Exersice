#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
const char* pstr[]={"Johnny Ng","Elson","Andy","Sarah Leong","Ben","Mia"};
const char* pstart("Your lucky star is ");

int count((sizeof pstr)/(sizeof pstr[0]));

cout<<sizeof pstr<<' '<<sizeof pstr[0]<<endl;

int dice(0);

cout<<endl
    <<"Pick a lucky star!"
    <<endl
    <<"Enter a number between 1 and "<<count<<":";
cin>>dice;

cout<<endl;
if(dice>=1&&dice<=count)
  cout<<pstart<<pstr[dice-1]<<".";
else
  cout<<"Sorry.";

cout<<endl;
return 0;
}
