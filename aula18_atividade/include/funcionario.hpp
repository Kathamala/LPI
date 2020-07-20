#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <string>

class funcionario{
    protected:
    std::string nome;
    float salario;
    int idade;
    
    public:
    std::string getNome();
    void setNome(std::string n);
    float getSalario();
    void setSalario(float f);
    int getIdade();
    void setIdade(int i);
};

#endif