#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <chrono>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    if (argc!=2){
        cerr << "Error en los argumentos uso: ./"<< argv[0] << " <tamaño estructuras>";
    }

    int tam = atoi(argv[1]);

    vector<int> vector_var(tam);
    list<int> list_var(tam);
    set<int> set_var;
    unordered_set<int> unordered_set_var;

     for (int i=1; i<tam; i++){
        vector_var.push_back(i);
        list_var.push_back(i);
        set_var.insert(i);
        unordered_set_var.insert(i);
    }

    // Comparativa Inserción
    cout < "__________________________________________________________" << endl;

    cout << "Comparando tiempos de inserción... " << endl;

    // Vector --------------------------------------------------------

    cout << "***************************************************" << endl;
    
    cout << "Vector:  " << endl;
    auto start_v = std::chrono::system_clock::now();
    vector_var.push_back(tam);
    auto end_v = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration_v = end_v - start_v;

    cout << "\tTiempo de inserción = " duration_v;

    cout << "***************************************************" << endl;

    // List ----------------------------------------------------------
    cout << "List:  " << endl;
    auto start_l = std::chrono::system_clock::now();
    list_var.push_back(tam);
    auto end_l = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration_l = end_l - start_l;
    cout << "\tTiempo de inserción = " duration_l;

    cout << "***************************************************" << endl;

    // Set ------------------------------------------------------------

    cout << "Set:  " << endl;
    auto start_s = std::chrono::system_clock::now();
    set_var.insert(tam);
    auto end_s = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration_s = end_s - start_s;
    cout << "\tTiempo de inserción = " duration_s;
    
    cout << "***************************************************" << endl;

    // Unordered Set --------------------------------------------------
    
    cout << "Unordered Set:  " << endl;
    auto start_us = std::chrono::system_clock::now();
    unordered_set_var.insert(tam);
    auto end_us = std::chrono::system_clock::now();

    std::chrono::duration<float,std::nano> duration_us = end_us - start_us;
    cout << "\tTiempo de inserción = " duration_us;

    cout << "***************************************************" << endl;

    // Comparativa borrado
    cout < "__________________________________________________________" << endl;
    cout << "Comparando tiempos de borrado... " << endl;


    // Comparativa acceso a elemento central
    cout < "__________________________________________________________" << endl;
    cout << "Comparando tiempos de acceso al elemento central... " << endl;


    // Comparativa de búsqueda
    cout < "__________________________________________________________" << endl;
    cout << "Comparando tiempos de búsqueda... " << endl;

}