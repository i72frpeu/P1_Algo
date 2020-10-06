#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double det(vector<vector<double>> &A, int n){
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
            aux = pow(-1, 2+j)*A[0][j]*det(B, n-1);
            deter +=aux;
        }
        return deter;
    }
}

int main(){

    double deter = 0;
    
    vector<vector<double>> A(4, vector<double>(4));

    A[0][0] = 1;
    A[0][1] = 3;
    A[0][2] = 5;
    A[0][3] = 7;
    A[1][0] = 2;
    A[1][1] = 8;
    A[1][2] = 9;
    A[1][3] = 9;
    A[2][0] = 2;
    A[2][1] = 7;
    A[2][2] = 8;
    A[2][3] = 9;
    A[3][0] = 1;
    A[3][1] = 5;
    A[3][2] = 7;
    A[3][3] = 2;

    deter = det(A, 4);

    cout<<deter<<endl;
}