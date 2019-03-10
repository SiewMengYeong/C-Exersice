# include <iostream>
using std::cout;
using std::endl;

void print_card(int x) 
{
const char suit[4]={'C','D','H','S'};
const char rank[13]={'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
cout<<suit[x/13]<<rank[x%13];
return;
}

int main()
{
    int i;
    int my_card[5];
    srand( time(NULL) );
    for (i=0; i<5; i++)         // Get_Five
        my_card[i] = rand() % 52;
    

    for (i=0; i<5; i++)
    {
        print_card(my_card[i]);
        cout << (i==4 ? '\n' : ' ');
    }
    return 0;
}
