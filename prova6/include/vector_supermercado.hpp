#ifndef WSN_VECTOR_SUPERMERCADO_H
#define WSN_VECTOR_SUPERMERCADO_H

#include <iostream>

template <class x>
class vector_supermercado{
    private:
    int size;
    int capacity;
    int top;
    x* elements;

    public:
    vector_supermercado(){
        this->size = 0;
        this->capacity = 1;
        this->top = -1;
        this->elements = new x[capacity];
    }

    bool isEmpty(){
        if(size == 0){
            return true;
        } else{
            return false;
        }
    }

    int sizeOf(){
        return this->size;
    }

    int capacityOf(){
        return this->capacity;
    }

    x front(){
        return this->elements[0];
    }

    x back(){
        return this->elements[size-1];
    }

    x *at(int i){
        return &elements[i];
    }

    void push(x element){
        if(size == capacity){
            try{
                x *elements2 = new x[capacity*2];

                for(int i = 0; i < this->capacity; ++i){
                    elements2[i] = elements[i];
                }
                delete[] elements;
                elements = elements2;

                this->capacity *= 2;  
            }
            catch (std::bad_alloc& b)
            {
                std::cout << "Tratador de erro chamado..." << std::endl;
                std::cout << "bad_alloc caught: " << b.what() << std::endl;
            }
        }
        this->elements[size] = element;
        ++size;
        ++top;
    }

    void pop(){
        if(top == -1){
            std::cout << "Fila vazia!" << std::endl;
        } else{
            this->elements[top--];
        }
    }

    x* begin(){
        return &elements[0];
    }
    x* end(){
        return &elements[0] + size;
    }

};

#endif