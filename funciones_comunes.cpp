#include "funciones_comunes.hpp"

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

void rellenarMatrizManual(vector<vector<double>> &A, int n){
    double aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"A["<<i<<"]["<<j<<"] = ";
            cin>>aux;
            A[i][j] = aux;
        }
    }
}

void rellenarMatrizAleatorio(vector<vector<double>> &A, int n){
    srand(time(NULL));
    double aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            aux = (double)(95 + rand() % (106 - 95));
            A[i][j] = aux/100;
        }
    }
}