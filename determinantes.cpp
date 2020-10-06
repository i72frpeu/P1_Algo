#include "determinantes.hpp"

using namespace std;

double resolverDeterminanteIterativo(vector <vector<double>> matriz, int n){
    double determinante = 1.0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(matriz[j][i] != 0){
                double aux = matriz[j][i];
                for(int k = 0; k < n; k++){
                    matriz[j][k] = matriz[j][k] - (aux/matriz[i][i])*matriz[i][k];
                }
            }
        }
        determinante = matriz[i][i] * determinante;
    }
    return determinante;
}

double resolverDeterminanteRecursivo(vector<vector<double>> &A, int n){
    double deter = 0, aux = 0;
    int c;
    if(n == 2){
        return A[0][0]*A[1][1] - A[1][0]*A[0][1];
    }else{
        for(int j = 0; j < n; j++){
            vector<vector<double>> B(n-1, vector<double>(n-1));
            for(int k = 1; k < n; k++){
                c = 0;
                for(int l = 0; l < n; l++){
                    if(l != j){
                        B[k-1][c] = A[k][l];
                        c++;
                    }
                }
            }
            aux = pow(-1, 2+j)*A[0][j]*resolverDeterminanteRecursivo(B, n-1);
            deter +=aux;
        }
        return deter;
    }
}