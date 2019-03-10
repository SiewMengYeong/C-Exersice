#include <iostream>

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
int x,y;
cout<<"Input your birth month and day, separated by a space -- ";
cin>>x>>y;
while(x>=1 && x<=12 && y>=1 && y<=31)
{
  if ((x<8 && x%2==0 && y==31)||(x>8 && x%2!=0 && y==31)||(x==2&&y==30))
    break;
  astrology(x,y);
  cout<<"Input your birth month and day, separated by a space -- ";
  cin>>x>>y;
}
return 0;
}
