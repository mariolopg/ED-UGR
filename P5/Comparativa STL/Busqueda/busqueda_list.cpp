#include <list>
#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    if (argc!=2)
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";

    int tam = atoi(argv[1]);
    bool parar = false; 

    list<int> list_var(tam);

     for (int i=1; i<tam; i++)
        list_var.push_back(i);

    list<int>::iterator it;

    auto start = std::chrono::system_clock::now();
    for(it = list_var.begin(); it != list_var.end() && !parar; ++it)
        if((*it) == tam)
            parar = true;
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

    cout << tam << "\t" << duration.count() << endl;

}