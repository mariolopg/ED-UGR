#include <unordered_set>
#include <chrono>
#include <iostream> 
 
using namespace std;

int main(int argc, char *argv[]){

    if (argc!=2)
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";

    int tam = atoi(argv[1]);

    unordered_set<int> unordered_set_var;
    

     for (int i=1; i<=tam; i++)
        unordered_set_var.insert(i);

    unordered_set<int>::iterator it = unordered_set_var.begin();

    auto start = std::chrono::system_clock::now();
    advance(it, tam/2-1);
    int elemento = (*it); // acceso al elemento tam/2
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

cout << tam << "\t" << duration.count() << endl;

}