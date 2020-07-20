#include "../include/funcionario.hpp"

std::string funcionario::getNome(){
    return this->nome;
}
void funcionario::setNome(std::string n){
    this->nome = n;
}
float funcionario::getSalario(){
    return this->salario;
}
void funcionario::setSalario(float f){
    this->salario = f;
}
int funcionario::getIdade(){
    return this->idade;
}
void funcionario::setIdade(int i){
    this->idade = i;
}