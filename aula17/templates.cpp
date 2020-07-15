#include <iostream>

/*
template <class myType> tipo funcao(){

}
Chamada --> funcao<tipo>();
*/

template <class x> void printArray(x *array, int size){
    for(int i = 0; i < size; i++){
        std::cout << array[i] << std::endl;
    }
}

int main(){
    int vet1[5] = {1, 2, 3, 4, 5};
    double vet2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char vet3[5] = {'a', 'b', 'c', 'd', 'e'};

    printArray<int>(vet1, 5);
    printArray<double>(vet2, 5);
    printArray<char>(vet3, 5);

    return 0;
}