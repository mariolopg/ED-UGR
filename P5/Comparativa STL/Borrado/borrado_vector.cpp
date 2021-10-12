#include <vector> 
#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    if (argc!=2)
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";

    int tam = atoi(argv[1]);

    vector<int> vector_var(tam);

    for (int i=1; i<=tam; i++)
        vector_var.push_back(i);
    
    auto start = std::chrono::system_clock::now();
    vector_var.erase(vector_var.begin() + tam/2 - 1); // eliminamos la posicion tam/2
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

    cout << tam << "\t" << duration.count() << endl;

}