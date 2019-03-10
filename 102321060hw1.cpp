#include <iostream>

int main()
{
    srand((unsigned) time(NULL));
    int count[11]={0};
    int i, n, dice1, dice2;
    for (i=0; i<100; i++)
    {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        n = dice1 + dice2; 
        ++count[n-2];
    }    
    for (i=0;i<11;i++)
      std::cout << i+2 << " - "<< count[i] << std::endl;
    
    return 0;
}
