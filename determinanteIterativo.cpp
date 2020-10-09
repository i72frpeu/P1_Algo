#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>


using namespace std;


void tiemposDeterminanteIterativo(int nMin, int nMax, int aumento, int control, vector <double> &tiemposReales, vector <double> &numeroElementos);
void ajustePolinomico(vector <double> &n, vector <double> &tiemposReales, vector <double> &a);
void calcularTiemposEstimadosPolinomio(const vector <double> &n, const vector <double> &a, vector <double> &tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, const vector <double> &a);

void determinanteIterativo(){

    int nMin = 0, nMax = 0, aumento = 0;
    int control = 0;
    double coef_det;
    vector <double> tiemposReales;
    vector <double> numeroElementos;
    vector <double> a_coef;
    vector <double> tiemposEstimados;

    cout<<"Introduzca el numero de filas y columnas  minimo(Trabajamos con matrices cuadradas)\n";
    cout<<"nMin = ";
    cin>>nMin;
    cout<<"Introduzca el numero de filas y columnas  maximo(Trabajamos con matrices cuadradas)\n";
    cout<<"nMax = ";
    cin>>nMax;
    cout<<"Introduzca el aumento de numeros de las filas y columnas de cada iteracion(Trabajamos con matrices cuadradas)\n";
    cout<<"aumento = ";
    cin>>aumento;

    while(control == 0){
        cout<<"Si quiere introducir los valores de la matriz manualmente pulse 1 \n";
        cout<<"Si quiere que la matriz se rellene aleatoriamente con numeros entre 0.95 y 1.05 pulse 2 \n";
        cin>>control;

        if(control != 1 && control != 2){
            cout<<"No ha introducido una opcion valida";
            control = 0;
        }
    }

    tiemposDeterminanteIterativo(nMin, nMax, aumento, control, tiemposReales, numeroElementos);
    ajustePolinomico(numeroElementos, tiemposReales, a_coef);
    calcularTiemposEstimadosPolinomio(numeroElementos, a_coef, tiemposEstimados);
    coef_det = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    cout<<"El coeficiente de determinacion es "<<coef_det<<"\n";

    cout<<"La ecuacion de la curva es f(n) = "<<a_coef[0]<<" + "<<a_coef[1]<<"*n + "<<a_coef[2]<<"*n^2 + "<<a_coef[3]<<"*n^3"<<endl;

    almacenarFichero(tiemposReales, numeroElementos, tiemposEstimados);

    system("gnuplot crear_tabla_iterativo.sh");
    
    double control2 = -1;

    while(control2 == -1){
        cout<<"Puede calcular el tiempo estimado de una matriz cuadrada n*n\n";
        cout<<"Si quiere calcular este tiempo introduzca el n\n";
        cout<<"Si no quiere calcular nada introduzca 0\nn = ";
        cin>>control2;
        if(control2 > 0){
            cout<<"El tiempo para "<<control2<<" elementos es "<<calcularTiempoEstimadoPolinomico(control2, a_coef)<<endl;
            control2 = -1;
        }
    }
}

void tiemposDeterminanteIterativo(int nMin, int nMax, int aumento, int control, vector <double> &tiemposReales, vector <double> &numeroElementos){
    int n = nMin;
    Clock time;
    while(n <= nMax){
        double t = 0;
        vector <vector<double>> matriz(n, vector<double>(n));
        if(control == 1){
            rellenarMatrizManual(matriz, n);
        }else{
            rellenarMatrizAleatorio(matriz, n);
        }
        time.start();
        resolverDeterminanteIterativo(matriz, n);
        if(time.isStarted()){
            time.stop();
            t = time.elapsed();
        }
        tiemposReales.push_back(t);
        numeroElementos.push_back(n);
        n = n + aumento;
    }
}

void ajustePolinomico(vector <double> &n, vector <double> &tiemposReales, vector <double> &a){
    vector<vector<double>> A(4, vector<double>(4));
    vector<vector<double>> B(4, vector<double>(1));
    vector<vector<double>> X(4, vector<double>(1));

    //std::cout.precision(4);

    cout<<"|   n    ||   t   |\n";

    for(int i = 0; i < n.size(); i++){
        cout<<std::fixed<<"| "<<n[i]<<"|| "<<tiemposReales[i]<<" || "<<endl;
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            A[i][j] = sumatorio(n,tiemposReales,i+j,0);
            if(j == 0){
                B[i][j] = sumatorio(n,tiemposReales,i,1);
            }
        }
    }

    resolverSistemaEcuaciones(A,B,4,X);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 1; j++){
            a.push_back(X[i][j]);
        }
    }
    
}

void calcularTiemposEstimadosPolinomio(const vector <double> &n, const vector <double> &a, vector <double> &tiemposEstimados){
    
    for(int i = 0; i < n.size(); i++){
        tiemposEstimados.push_back(a[0]+a[1]*n[i]+a[2]*pow(n[i],2)+a[3]*pow(n[i],3));
    }
}


double calcularTiempoEstimadoPolinomico(const double &n, const vector <double> &a){
    return (a[0]+a[1]*n+a[2]*pow(n,2)+a[3]*pow(n,3));
}