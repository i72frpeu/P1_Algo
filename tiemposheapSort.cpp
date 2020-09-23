#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>
#include "ClaseTiempo.cpp"
#include "heapSort.hpp"
#include "sistemaEcuaciones.cpp"

using namespace std;

void rellenarVector(vector<int> &v);
void tiemposOrdenacionHeapSort(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos);
void almacenarFichero(vector <double> &tiemposReales, vector <double> &numeroElementos);
void ajusteNlogN(const vector <double> &n, vector <double> &tiemposReales, vector <double> &a);
double sumatorio(vector <double> &n, vector <double> &t, int expN, int expT);

void ordenacionHeapSort(){
    int nMin, nMax, incre, repe;
    vector <double> tiemposReales;
    vector <double> numeroElementos;

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

void tiemposOrdenacionHeapSort(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos){
    int n = nMin;
    Clock time;
    while (n <= nMax){
        double tmedio = 0;
        for(int i = 0; i < repeticiones; i++){
            vector <int> v(n);
            rellenarVector(v);
            time.start();
            heapSort(v);

            if(time.isStarted()){
                time.stop();
                tmedio = tmedio + time.elapsed();
            }
        }
        tmedio = tmedio / repeticiones;
        tiemposReales.push_back(tmedio);
        numeroElementos.push_back(n);
        n = n + incremento;
    }
}

void almacenarFichero(vector <double> &tiemposReales, vector <double> &numeroElementos){
    ofstream f("tiempos.txt");
    for(int i = 0; i < numeroElementos.size(); i++){
        f<<numeroElementos[i]<<" "<<tiemposReales[i]<<"\n";
    }
    f.close();
}


void ajusteNlogN(const vector <double> &n, vector <double> &tiemposReales, vector <double> &a){
    vector<vector<double>> A(n.size(), vector<double>(n.size()));
    vector<vector<double>> B(n.size(), vector<double>(1));
    vector<vector<double>> X(n.size(), vector<double>(1));
    
    for(int i = 0; i < n.size(); i++){
        a[i] = n[i]*log(n[i]);
    }

    for(int i = 0; i < n.size(); i++){
        for(int j = 0; j < n.size(); j++){
            A[i][j] = sumatorio(a,tiemposReales,i+j,0);
            if(j == 0){
                B[i][j] = sumatorio(a,tiemposReales,i,1);
            }
        }
    }

    resolverSistemaEcuaciones(A,B,n.size(),X);

}

double sumatorio(vector <double> &n, vector <double> &t, int expN, int expT){

}

