#include <iostream>
#include <vector>
#include "sistemaEcuaciones.cpp"

using namespace std;

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

int main(){
    vector <double> a = {1,2,3,4};
    vector <double> b = {3,4,5,6};
    vector <double> ultimo;
    vector<vector<double>> A(2, vector<double>(2));
    vector<vector<double>> B(2, vector<double>(1));
    vector<vector<double>> X(2, vector<double>(1));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            A[i][j] = sumatorio(a,b,i+j,0);
            if(j == 0){
                B[i][j] = sumatorio(a,b,i,1);
            }
        }
    }

    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout<<"A["<<i<<"]["<<j<<"] = "<<A[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1; j++){
            cout<<"B["<<i<<"]["<<j<<"] = "<<B[i][j]<<" ";
        }
        cout<<"\n";
    }

    resolverSistemaEcuaciones(A,B,2,X);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1; j++){
            cout<<"X["<<i<<"]["<<j<<"] = "<<X[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 1; j++){
            ultimo.push_back(X[i][j]);
        }
    }

    for(int i = 0; i < 2; i++){
            cout<<"ultimo["<<i<<"] = "<<ultimo[i]<<" ";
    }

}