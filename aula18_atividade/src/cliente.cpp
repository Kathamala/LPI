#include "../include/cliente.hpp"

std::string cliente::getNome(){
    return this->nome;
}
void cliente::setNome(std::string n){
    this->nome = n;
}
int cliente::getIdade(){
    return this->idade;
}
void cliente::setIdade(int i){
    this->idade = i;
}
std::string cliente::getSexo(){
    return this->sexo;
}
void cliente::setSexo(std::string s){
    this->sexo = s;
}