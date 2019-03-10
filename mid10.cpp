#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

int main()
{
    const unsigned short N = 4;
    char matrix[N * N + 1];
    char plaintext[] = "Uiorknrsred a eCraopi oumtpler loA.tuoA.tuoA.tuo";

    char ciphertext[ sizeof(plaintext) ];
    char *p = plaintext;    
    unsigned i, j;
    
    while (p < plaintext+ sizeof(plaintext))
    {
      if (matrix[i*N + j] == *p) 
        matrix[i*N + j] = *p; 
      else 
        matrix[i*N + j] = 'A';
//      matrix[i*N + j] = *p ? *p : 'A';
      p++;
    }
    cout << endl;

    return 0;
}
