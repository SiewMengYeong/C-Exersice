# include <iostream>
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

int bridge_comp(int x,int y)
{
return (x-y);
}

int big2_comp(int x,int y)
{
return (x%13-y%13);
}

void exchange_sort(int a[], int n, int (*pcomp)(int, int))
{
    int i, j, temp;
    for (i=0; i<n-1; i++)
        for (j=i+1; j<n; j++)
            if ( pcomp(a[i], a[j]) > 0 )
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main()
{
    int i;
    const int N = 13;
    int my_card[N];
    srand( time(NULL) );
    get_cards(my_card, N);

    print_cards(my_card, N);

    cout << "===== Sorted by bridge order =====\n";
    exchange_sort(my_card, N, bridge_comp);
    print_cards(my_card, N);

    cout << "===== Sorted by Big2 order =====\n";
    exchange_sort(my_card, N, big2_comp);
    print_cards(my_card, N);
    return 0;
}
