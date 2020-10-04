#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void rellenarMatrizAleatorio(vector<vector<double>> &A, int filas, int columnas);
void rellenarMatrizManual(vector<vector<double>> &A, int filas, int columnas);

void determinanteIterativo(){

    int filas = 0, columnas = 0, control = 0;

    while(columnas == 0 || filas == 0){
        cout<<"Introduzca el numero de filas y de columnas de la matriz:\n";
        cout<<"Filas = ";
        cin>>filas;
        cout<<"Columnas = ";
        cin>>columnas;

        if(columnas <= 0 || filas <= 0){
            cout<<"Ha introducido mal el valor de las filas o las colummas, vuelva a introducir\n";
            columnas = 0;
            filas = 0;
        }
    }

    vector<vector<double>> A(filas, vector<double>(columnas));

    while(control == 0){
        cout<<"Si quiere introducir los valores de la matriz manualmente pulse 1 \n";
        cout<<"Si quiere que la matriz se rellene aleatoriamente con numeros entre 0.95 y 1.05 pulse 2 \n";
        cin>>control;

        if(control == 1){
            rellenarMatrizManual(A, filas, columnas);
        }else{
            if(control == 2){
            rellenarMatrizAleatorio(A, filas, columnas);
        }else{
            cout<<"No ha introducido una opcion valida";
            control = 0;
        }
        } 
    }
    
}

void rellenarMatrizManual(vector<vector<double>> &A, int filas, int columnas){
    double aux;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout<<"A["<<i<<"]["<<j<<"] = ";
            cin>>aux;
            A[i][j] = aux;
        }
    }
}

void rellenarMatrizAleatorio(vector<vector<double>> &A, int filas, int columnas){
    srand(time(NULL));
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            A[i][j] = (95 + rand() % (106 - 95))/100;
        }
    }
}