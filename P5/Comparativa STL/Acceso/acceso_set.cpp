#include <set>
#include <chrono>
#include <iostream> 

using namespace std;

int main(int argc, char *argv[]){

 if (argc!=2)
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";

    int tam = atoi(argv[1]);

    set<int> set_var;   

     for (int i=1; i<=tam; i++)
        set_var.insert(i);
    
    set<int>::iterator it = set_var.begin();

    auto start = std::chrono::system_clock::now();
    advance (it, tam/2-1);
    int elemento = (*it); // acceso al elemento tam/2
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

    cout << tam << "\t" << duration.count() << endl;

}