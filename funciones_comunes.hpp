#include <vector>
#include <cmath>
#include <fstream>

double sumatorio(vector <double> &n, vector <double> &t, int expN, int expT);
double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados);
void rellenarMatrizAleatorio(vector<vector<double>> &A, int n);
void rellenarMatrizManual(vector<vector<double>> &A, int n);
void almacenarFichero(vector <double> &tiemposReales, vector <double> &numeroElementos, vector <double> &tiemposEstimados);