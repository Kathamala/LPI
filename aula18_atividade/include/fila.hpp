#ifndef FILA
#define FILA

#include <iostream>

template <class x>
class fila{
    private:
    int size;
    int top;
    x* elements;

    public:
    fila(int s){
        this->size = s;
        this->top = -1;
        this->elements = new x[size];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        } else{
            return false;
        }
    }

    int sizeOf(){
        return this->size;
    }

    x front(){
        return this->elements[0];
    }

    x back(){
        return this->elements[top];
    }

    void push(x element){
        if(top == size-1){
            std::cout << "Fila cheia" << std::endl;
        } else{
            this->elements[++top] = element;
        }
    }

    void pop(){
        if(top == -1){
            std::cout << "Fila vazia" << std::endl;
        } else{
            this->elements[top--];
        }
    }
};

#endif