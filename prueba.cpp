#include <iostream>
#include <vector>
#include "sistemaEcuaciones.cpp"

using namespace std;

int main(){
    vector<vector<double>> matriz(2,vector<double>(2));
    matriz[0][0] = 11;
    matriz[0][1] = 3606.693;
    matriz[1][0] = 3606.693;
    matriz[1][1] = 1257202.607;

    vector<vector<double>> b(2,vector<double> (1));
    b[0][0] = 859.84;
    b[1][0] = 298531.964;

    int n = 2;

    vector<vector<double>> x(2,vector<double> (1));

    resolverSistemaEcuaciones(matriz, b, n, x);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1; j++){
            cout<<x[i][j]<<"  ";
        }
        cout<<"\n";
    }

}