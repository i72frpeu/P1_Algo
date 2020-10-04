#include <iostream>
#include "funciones.hpp"


int main(){
    int opc = -1;

    while(opc != 0){
        std::cout<<"Estas son los apartados que puede realizar el programa \n"
        <<"1 -> Ordenacion HeapSort de un vector\n"
        <<"2 -> Calculo de determinante con metodo Iterativo\n"
        <<"3 -> Calculo de determinante con método Recursivo \n"
        <<"Introduzca el nuemro del apartado para empezar el aparatdo que desee: ";

        std::cin>> opc;

        switch (opc){
            case (1):
                ordenacionHeapSort();  
            break;

            case (2):
                determinanteIterativo();
            break;

            case (3):
                //determinanteRecursivo();
                std::cout<<"3\n";
            break;
    
            default:
                std::cout<<"Lo sentimos, la opción que ha introducido no la puedo realizar \n";
            break;
        }

        std::cout<<"Si quiere salir pulse 0, pulse otro numero si quiere volver a empezar\n";
        std::cin>>opc;
    } 
}