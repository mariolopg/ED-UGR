#include <iostream>
#include <Pila_max_VD.h>

using namespace std;

int main(){

PilaMaxVD p; 
int i;
for ( i=10; i>=0 ; i--)
  p.poner(i);

while (!p.vacia() ){
  Elemento x = p.tope();
  cout << x <<endl;
  p.quitar();
}
  return 0;
}
 