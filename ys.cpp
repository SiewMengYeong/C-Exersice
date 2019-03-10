
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int num;
	char text[80];
	cout<<"Input a num."<<endl;
	cin>>num;
        switch(num)
	{
	case 1:
        cout<<"text=";
        cin.getline(text,80,'\0');
	cout<<text<<endl;		

	}
return 0;
}

