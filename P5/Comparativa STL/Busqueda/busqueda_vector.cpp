#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){

    if (argc!=2)
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";

    int tam = atoi(argv[1]);
 
    vector<int> vector_var(tam);

    for (int i=1; i<=tam; i++)
        vector_var.push_back(i);
    
    auto start = std::chrono::system_clock::now();
    binary_search(vector_var.begin(), vector_var.end(), tam);
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration = end - start;

    cout << tam << "\t" << duration.count() << endl;

}