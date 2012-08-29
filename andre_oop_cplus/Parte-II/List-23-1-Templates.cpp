#include <iostream>

using namespace std;

// Fun��o Template recursiva
template<int N>   
void f()
{
  f<N-1>(); // recurs�o
  cout << "N=" << N << endl;
}

// Especializa��o para int == 0
template<>        
void f<0>() 
{
  cout << "N=" << 0 << endl;
}


int main()
{
  f<10>(); // cria inst�ncia da fun��o template com N=10

  return 0;
}
