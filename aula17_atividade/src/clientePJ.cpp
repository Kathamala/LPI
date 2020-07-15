#include "../include/clientePJ.hpp"

std::string clientePJ::getRazaoSocial(){
    return this->RazaoSocial;
}
void clientePJ::setRazaoSocial(std::string r){
    this->RazaoSocial = r;
}
std::string clientePJ::getCNPJ(){
    return this->CNPJ;
}
void clientePJ::setCNPJ(std::string c){
    this->CNPJ = c;
}