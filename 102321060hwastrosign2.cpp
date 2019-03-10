#include <iostream>
#include <ctime>

using std::cin; 
using std::cout; 
using std::endl; 

void astrology(int m,int d)
{
int i;
const char* astrological_sign[] = { "Aries", "Taurus", "Gemini", 
"Cancer", 
"Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", 
"Aquarius", "Pisces" };

i=m-3;
if (i<0)
  i+=12;
cout<<"Your astrological sign is ";

if (i+1==1)
{
if (d>=21)
  cout<<astrological_sign[i]<<endl;
else
  cout<<astrological_sign[i+11]<<endl;
}

if (i+1==3)
{
if (d>=21)
  cout<<astrological_sign[i]<<endl;
else
  cout<<astrological_sign[i-1]<<endl;
}


if (i+1==2||i+1==11)
{
if (d>=20)
  cout<<astrological_sign[i]<<endl;
else
  cout<<astrological_sign[i-1]<<endl;
}

if (i+1==12)
{
if (d>=19)
  cout<<astrological_sign[i]<<endl;
else
  cout<<astrological_sign[i-1]<<endl;
}

if (i+1>=5&&i+1<=8)
{
if (d>=23)
  cout<<astrological_sign[i]<<endl;
else
  cout<<astrological_sign[i-1]<<endl;
}

if (i+1==4||i+1==9||i+1==10)
{
if (d>=22)
  cout<<astrological_sign[i]<<endl;
else
  cout<<astrological_sign[i-1]<<endl;
}

return;
}

int main()
{
int y,m,d,year;

time_t rawtime;
struct tm * timeinfo;

time(&rawtime);
timeinfo=localtime(&rawtime);

cout<<"================================================"<<endl;
cout<<"Input the year, month and day of your birthday, separated by spaces."<<endl;
cout<<"Supply 3 zeros when you want to terminate the program."<<endl;
cin>>y>>m>>d;
while(m>=1 && m<=12 && d>=1 && d<=31)
{
  if ((m<8 && m%2==0 && d==31)||(m>8 && m%2!=0 && d==31)||(m==2&&d==30))
    break;
  year=timeinfo->tm_year+1900-y;
  if (year<0)
    cout<<"You are not born yet!"<<endl;
  if (year>=0)
    astrology(m,d);
  if (year>=100)
    cout<<"It's hard to imagine that you are older than 100 years old."<<endl;
  if (year==0)
    cout<<"It's hard to believe that you are younger than 1 year old."<<endl;
  cout<<"================================================"<<endl;
  cout<<"Input the year, month and day of your birthday, separated by spaces."<<endl;
  cout<<"Supply 3 zeros when you want to terminate the program."<<endl;
  cin>>y>>m>>d;
}
return 0;
}
