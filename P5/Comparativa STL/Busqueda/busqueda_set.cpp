#include <set>
#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

 if (argc!=2)
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";

    int tam = atoi(argv[1]);

    set<int> set_var;

     for (int i=1; i<tam; i++)
        set_var.insert(i);

    auto start = std::chrono::system_clock::now();
    set_var.find(tam);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

    cout << tam << "\t" << duration.count() << endl;

}