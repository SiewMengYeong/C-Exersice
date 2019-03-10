#include <iostream>
#include <iomanip>
#include <cstring>

using std::cout;
using std::endl;
using std::setw;
using std::cin;
using std::hex;

int main()
{
/*
int a=5;
int b;
b=a*4;
cout<<setw(5)<<b<<setw(4)<<a<<endl;
cout<<sizeof a<<endl;
int array[]={1,44,66};
char* name[]={"ad","qq","ee"};
cout<<sizeof a<<'\t'<<sizeof array<<'\t'<<array[0]<<endl;
cout<<sizeof name<<'\t'<<sizeof name[0]<<endl;
*/

char str1[]="Ye ong ";
char str2[]="Siew  ";
char str3[3];;
/*
//strcat(str1,str2);
cout<<strlen(str1)<<endl;
strcpy(str3,str1);
cout<<strcmp(str1,str2)<<endl;
*/
/*
char *r=strstr( str1, str3 );
cout<<r<<endl;
*/
/*
strncpy(str3,str1,6);
cout<<str3<<endl;
*/
        int x;
	char text[99];

/*	cout<<"Input a num."<<endl;
        cin>>x;
*/
/*
        cout<<"Input a text."<<endl;
	cin.getline(text,99,'\n');
	cout<<text<<endl;		
*/
/*
for (int i=0;i<26;i++)
  cout<<i<<' '<<char ('A'+i)<<endl;
*/
//cout<<(-1?5:2)<<endl;
cout<<hex<<((((16<<8)|20)<<8|30)<<8|40)<<endl;
return 0;
}
