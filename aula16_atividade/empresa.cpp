    #include "empresa.hpp"
    
    std::string Empresa::getNome(){
        return this->nome;
    }

    void Empresa::setNome(std::string nome){
        this->nome = nome;
    }

    std::string Empresa::getCNPJ(){
        return this->CNPJ;
    }

    void Empresa::setCNPJ(std::string CNPJ){
        this->CNPJ = CNPJ;
    }