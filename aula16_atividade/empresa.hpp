#ifndef W5N_EMPRESA_H
#define W5N_EMPRESA_H

#include <string>

class Empresa{
    private:
    std::string nome;
    std::string CNPJ;

    public:
    std::string getNome();
    void setNome(std::string nome);
    std::string getCNPJ();
    void setCNPJ(std::string CNPJ);
};

#endif