#include <iostream>

template <class T>
class Pilha{
    private:
    int size;
    int top;
    T* elements;

    public:
    Pilha(int s){
        this->size = s;
        this->top = -1;
        this->elements = new T[size];
    }
    void push(T element){
        if(top == (size-1)){
            std::cout << "Pilha cheia" << std::endl;
        } else{
            this->elements[++top] = element;
        }
    }
    void pop(){
        if(top == -1){
            std::cout << "Pilha vazia" << std::endl;
        } else{
            this->elements[top--];
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        } else{
            return false;
        }
    }
    T back(){
        return this->elements[top];
    }
};

int main(){
    Pilha<int> pilha(3);

    pilha.push(1);
    pilha.push(2);
    pilha.push(3);
    pilha.push(4);

    std::cout << pilha.back() << std::endl;
    
    return 0;
}