#include "funcionario.hpp"

std::string Funcionario::getNome(){
    return this->nome;
}
void Funcionario::setNome(std::string nome){
    this->nome = nome;
}
Empresa Funcionario::getEmpresa(){
    return this->empresa;
}
void Funcionario::setEmpresa(Empresa empresa){
    this->empresa = empresa;
}
std::string Funcionario::getDepartamento(){
    return this->departamento;
}
void Funcionario::setDepartamento(std::string departamento){
    this->departamento = departamento;
}
double Funcionario::getSalario(){
    return this->salario;
}
void Funcionario::setSalario(double salario){
    this->salario = salario;
}
std::string Funcionario::getDataAdimicao(){
    return this->dataDeAdimicao;
}
void Funcionario::setDataAdimicao(std::string data){
    this->dataDeAdimicao = data;
}