#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "ClaseTiempo.cpp"
#include "heapSort.hpp"
#include "sistemaEcuaciones.cpp"

using namespace std;

void rellenarVector(vector<int> &v);
void tiemposOrdenacionHeapSort(int nMin, int nMax, int repeticiones, int incremento, vector <double> &tiemposReales, vector <double> &numeroElementos);
void almacenarFichero(vector <double> &tiemposReales, vector <double> &numeroElementos, vector <double> &tiemposEstimados);
void ajusteNlogN(const vector <double> &n, vector <double> &tiemposReales, vector <double> &a);
double sumatorio(vector <double> &n, vector <double> &t, int expN, int expT);
void calcularTiemposEstimados(const vector <double> &n, const vector <double> &a, vector <double> &tiemposEstimados);
double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados);
double calcularTiempoEstimadoNlogN(const double &n, vector <double> &a);

void ordenacionHeapSort(){
    int nMin, nMax, incre, repe;
    vector <double> tiemposReales;
    vector <double> tiemposEstimado;
    vector <double> numeroElementos;
    vector <double> coeficientes_a;
    double coef_det;

    cout<<"Introduzca el valor minimo de elementos del vector: ";
    cin >> nMin;
    cout<<"Introduzca el valor máximo de elementos del vector: ";
    cin>> nMax;
    cout<<"Introduzca el valor del incremento del valor de elementos: ";
    cin>>incre;
    cout<<"Introduzca el numero de repeticiones que se hará la ordenación: ";
    cin>>repe;

    tiemposOrdenacionHeapSort(nMin, nMax, repe, incre, tiemposReales, numeroElementos);
    ajusteNlogN(numeroElementos, tiemposReales, coeficientes_a);
    calcularTiemposEstimados(numeroElementos, coeficientes_a, tiemposEstimado);
    coef_det = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimado);

    cout<<"La ecuacion de la curva ajustada es la siguiente: \nf(x) = "<<coeficientes_a[0]<<" + "<<coeficientes_a[1]<<"*nlog(n)\n";
    cout<<"El coeficiente de determinacion es "<< coef_det<<endl;

    almacenarFichero(tiemposReales, numeroElementos, tiemposEstimado);

    system("gnuplot crear_tabla.sh");

    double control = -1;

    while(control == -1){
        cout<<"Puede calcular el tiempo estimado de un vector de n elemntos\n";
        cout<<"Si quiere calcular este tiempo introduzca el numero de elementos\n";
        cout<<"Si no quiere calcular nada introduzca 0\nn = ";
        cin>>control;
        if(control > 0){
            cout<<"El tiempo para "<<control<<" elementos es "<<calcularTiempoEstimadoNlogN(control, coeficientes_a)<<endl;
            control = -1;
        }
    }

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

void almacenarFichero(vector <double> &tiemposReales, vector <double> &numeroElementos,  vector <double> &tiempoEstimados){
    ofstream f("tiempos.txt");
    for(int i = 0; i < numeroElementos.size(); i++){
        f<<numeroElementos[i]<<" "<<tiemposReales[i]<<" "<<tiempoEstimados[i]<<"\n";
    }
    f.close();
}

void ajusteNlogN(const vector <double> &n, vector <double> &tiemposReales, vector <double> &a){
    vector<vector<double>> A(2, vector<double>(2));
    vector<vector<double>> B(2, vector<double>(1));
    vector<vector<double>> X(2, vector<double>(1));
    vector <double> nlogn;

    //std::cout.precision(4);

    
    for(int i = 0; i < n.size(); i++){
        double x = log10(n[i]);
        x = x * n[i];
        nlogn.push_back(x);
    }


    cout<<"|   n    ||   t   ||   z  |\n";

    for(int i = 0; i < n.size(); i++){
        cout<<std::fixed<<"| "<<n[i]<<"|| "<<tiemposReales[i]<<" || "<<nlogn[i]<<endl;
    }
    

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            A[i][j] = sumatorio(nlogn,tiemposReales,i+j,0);
            if(j == 0){
                B[i][j] = sumatorio(nlogn,tiemposReales,i,1);
            }
        }
    }

    resolverSistemaEcuaciones(A,B,2,X);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1; j++){
            a.push_back(X[i][j]);
        }
    }

}

double sumatorio(vector <double> &n, vector <double> &t, int expN, int expT){
    double sum = 0;
    if(expT == 0){
        for(int i = 0; i < n.size(); i++){
            sum = sum + pow(n[i],expN);
        }
    }else{
        for(int i = 0; i < n.size(); i++){
            sum = sum + (pow(t[i],expT) * pow(n[i], expN));
        }
    }
}

void calcularTiemposEstimados(const vector <double> &n, const vector <double> &a, vector <double> &tiemposEstimados){
    for(int i = 0; i < n.size(); i++){
        tiemposEstimados.push_back(a[0] + a[1]*n[i]*log10(n[i])); 
    }
}

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados){
    double media_tr = 0.0, media_te = 0.0, var_tr = 0.0, var_te = 0.0; 
    int n = tiemposEstimados.size();

    for(int i = 0; i < n; i++){
        media_tr = media_tr + tiemposReales[i];
        media_te = media_te + tiemposEstimados[i];
    }

    media_tr = media_tr/n;
    media_te = media_te/n;

    for(int i = 0; i < n; i++){
        var_tr = var_tr + pow(tiemposReales[i] - media_tr, 2);
        var_te = var_te + pow(tiemposEstimados[i] - media_te, 2);
    }

    var_tr = var_tr/n;
    var_te = var_te/n;

    return var_te/var_tr;
}

double calcularTiempoEstimadoNlogN(const double &n, vector <double> &a){
    return (a[0] + a[1]*n*log10(n));
}