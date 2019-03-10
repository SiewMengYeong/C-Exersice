# include <iostream>

using std::cin;
using std::cout;
using std::endl;

int get_cards(int my_card[],int N)
{
for (int i=0; i<N;i++)
{
   my_card[i] = rand() % 52;
   for(int j=0;j<i;j++)
   {
     if ( my_card[i]== my_card[j])
     { 
       i--;
       j=i;
     }
   }
}
return my_card[N];
}

void print_cards(int x[],int N) 
{
const char* suit[4]={"C","D","H","S"};
const char* rank[13]={"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
for (int i=0; i<N; i++)
   {
     cout<<suit[x[i]/13]<<rank[x[i]%13];
     cout << (i==N-1 ? '\n' : ' ');
   }
return;
}

void print_cards(int x[],int N,const char* y)
{
const char* suit[4]={"梅花","方塊","紅心","黑桃"};
const char* rank[13]={"2", "3", "4", "5", "6", "7", "8", "9", "十", "J",
"Q", "K", "A"};
for (int i=0; i<N; i++)
   {
     cout<<suit[x[i]/13]<<rank[x[i]%13];
     cout << (i==N-1 ? '\n' : ' ');
   }
return;
}

int main()
{
    char x[10];
    int i;
    const int N = 52;
    int my_card[N];
    srand( time(NULL) );
    for(;;)
{
    get_cards(my_card, N);

//    print_cards(my_card, N);
    for(int i=0;i<52-2;i++)
    {
    print_cards(my_card, 2+i,"Chinese");
    cout<<"y or n? ";    
    cin>>x;
    if (x[0]=='n')
      break;
    }
    cout<<"continue? ";
    cin>>x;
    if (x[0]=='n')
      break;
}
    return 0;
}
