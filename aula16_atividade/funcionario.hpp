#ifndef W5N_FUNCIONARIO_H
#define W5N_FUNCIONARIO_H

#include "empresa.hpp"

class Funcionario{
    private:
    std::string nome;
    Empresa empresa;
    std::string departamento;
    double salario;
    std::string dataDeAdimicao;

    public:
    std::string getNome();
    void setNome(std::string nome);
    Empresa getEmpresa();
    void setEmpresa(Empresa empresa);
    std::string getDepartamento();
    void setDepartamento(std::string departamento);
    double getSalario();
    void setSalario(double salario);
    std::string getDataAdimicao();
    void setDataAdimicao(std::string data);

};

#endif