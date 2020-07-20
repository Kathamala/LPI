#ifndef CLIENTEPJ
#define CLIENTEPJ

#include <string>

#include "cliente.hpp"

class clientePJ : public cliente{
    private:
    std::string RazaoSocial;
    std::string CNPJ;

    public:
    std::string getRazaoSocial();
    void setRazaoSocial(std::string r);
    std::string getCNPJ();
    void setCNPJ(std::string c);
};

#endif