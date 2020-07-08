#include "cliente.hpp"

int cliente::quantidadeClientes;

cliente::cliente(){
    this->quantidadeClientes++;
}

cliente::~cliente(){

}
