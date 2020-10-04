#include <iostream>
#include<iomanip>

int main(){
    double x = 123456789012839;
    std::cout.precision(2);
    std::cout<<std::fixed<<x<<std::endl;
}