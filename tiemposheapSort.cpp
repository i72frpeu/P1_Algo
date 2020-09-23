#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>
#include "ClaseTiempo.cpp"
#include "heapSort.hpp"

using namespace std;

void rellenarVector(vector<int> &v);
void tiemposOrdenacionHeapSort(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <int> &numeroElementos);
void almacenarFichero(vector <double> &tiemposReales, vector <int> &numeroElementos);
void escribirVector(vector <int> &v);

void ordenacionHeapSort(){
    int nMin, nMax, incre, repe;
    vector <double> tiemposReales;
    vector <int> numeroElementos;

    cout<<"Introduzca el valor minimo de elementos del vector: ";
    cin >> nMin;
    cout<<"Introduzca el valor máximo de elementos del vector: ";
    cin>> nMax;
    cout<<"Introduzca el valor del incremento del valor de elementos: ";
    cin>>incre;
    cout<<"Introduzca el numero de repeticiones que se hará la ordenación: ";
    cin>>repe;

    tiemposOrdenacionHeapSort(nMin, nMax, repe, incre, tiemposReales, numeroElementos);
    almacenarFichero(tiemposReales, numeroElementos);
}

void rellenarVector(vector<int> &v){
    
    srand(time(NULL));
    for(int i = 0; i < v.size(); i++){
        v[i] = rand() % 9999999;
    }

}

void tiemposOrdenacionHeapSort(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <int> &numeroElementos){
    int n = nMin;
    //Clock time;
    while (n <= nMax){
        double tmedio = 0;
        for(int i = 0; i < repeticiones; i++){
            vector <int> v(n);
            rellenarVector(v);
            escribirVector(v);
            //time.start();
            heapSort(v);
            escribirVector(v);
        }
        n = n + incremento;
    }
            /*if(time.isStarted()){
                time.stop();
                tmedio = tmedio + time.elapsed();
            }
        }
        tmedio = tmedio / repeticiones;
        tiemposReales.push_back(tmedio);
        numeroElementos.push_back(n);
        n = n + incremento;
    }*/
}

void almacenarFichero(vector <double> &tiemposReales, vector <int> &numeroElementos){
    ofstream f("tiempos.txt");
    for(int i = 0; i < numeroElementos.size(); i++){
        f<<numeroElementos[i]<<","<<tiemposReales[i]<<"\n";
    }
    f.close();
}

void escribirVector(vector <int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<"v["<<i<<"]-> "<<v[i]<<"\n";
    }
}