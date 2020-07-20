#ifndef CLIENTE
#define CLIENTE

#include <string>

class cliente{
    private:
    std::string nome;
    int idade;
    std::string sexo;

    public:
    std::string getNome();
    void setNome(std::string n);
    int getIdade();
    void setIdade(int i);
    std::string getSexo();
    void setSexo(std::string s);
};

#endif