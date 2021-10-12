#include <list>
#include <chrono>
#include <iostream> 

using namespace std;

int main(int argc, char *argv[]){

    if (argc!=2)
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";

    int tam = atoi(argv[1]);

    list<int> list_var(tam);
    list<int>::iterator it = list_var.begin();

     for (int i=1; i<=tam; i++)
        list_var.push_back(i);

    auto start = std::chrono::system_clock::now();
    advance(it, tam/2-1);
    int elemento = (*it); // accedemos a la poscion tam/2
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

    cout << tam << "\t" << duration.count() << endl;

}