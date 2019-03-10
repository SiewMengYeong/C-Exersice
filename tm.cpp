#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
int y,m,d;
time_t rawtime;
struct tm * timeinfo;

time(&rawtime);
timeinfo=localtime(&rawtime);

cout<<"Date(yyyy mm dd):";
cin>>y>>m>>d;
cout<<endl;

(timeinfo->tm_year)=y-1900;
(timeinfo->tm_mon)=m-1;
(timeinfo->tm_mday)=d+42;

mktime(timeinfo);

cout<<asctime(timeinfo);
return 0;
}
