#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "sistemaEcuaciones.cpp"
#include "heapSort.hpp"

using namespace std;

int main(){
    srand(time(NULL));
    vector <int> v1;
    vector <int> v2;

for(int i = 0; i < 10; i++){
        v1.push_back(rand() % 100); 
        v2.push_back(v1[i]);
}

for(int i = 0; i < 10; i++){
       std::cout<<v1[i]<<" ";
}

cout<<"\n";

for(int i = 0; i < 10; i++){
       std::cout<<v2[i]<<" ";
}

cout<<"\n";

quickSort(v1, 0, v1.size()-1);

for(int i = 0; i < 10; i++){
       std::cout<<v1[i]<<" ";
}

cout<<"\n";

heapSort(v2);

for(int i = 0; i < 10; i++){
       std::cout<<v2[i]<<" ";
}

cout<<"\n";

}