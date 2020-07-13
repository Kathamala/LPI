#include <iostream>
#include <vector>

#include "funcionario.hpp"

int main(){

    Empresa e1;
    e1.setNome("Casas Bahia");
    e1.setCNPJ("00.000.000/0000-00");
    std::vector<Funcionario> vetorFunc;
    int quantidade;

    std::cout << "Quantos funcionários deseja cadastrar: " << std::endl;
    std::cin >> quantidade;

    for(int i = 0; i < quantidade; i++){
        Funcionario f;
        f.setEmpresa(e1);

        std::cout << "Indique o nome do funcionario " << i+1 << ": " << std::endl;
        std::string nome;
        std::cin >> nome;
        f.setNome(nome);

        std::cout << "Indique o salário do funcionario " << i+1 << ": " << std::endl;
        double salario;
        std::cin >> salario;
        f.setSalario(salario);       

        std::cout << "Indique o departamento do funcionario " << i+1 << ": " << std::endl;
        std::string departamento;
        std::cin >> departamento;
        f.setDepartamento(departamento);

        std::cout << "Indique a data de adimição do funcionario " << i+1 << ": " << std::endl;
        std::string data;
        std::cin >> data;
        f.setDataAdimicao(data);

        vetorFunc.push_back(f); 
    }

    std::string deparAumento;
    std::cout << "Qual o departamento que receberá um aumento de 10%: " << std::endl;
    std::cin >> deparAumento;

    std::cout << "# Nome : Novo Salário" << std::endl;
    int verificador = 0;
    for(int i = 0; i < vetorFunc.size(); i++){
        if(vetorFunc[i].getDepartamento() == deparAumento){
            vetorFunc[i].setSalario(vetorFunc[i].getSalario() + (vetorFunc[i].getSalario()/10));
            std::cout << "- " << vetorFunc[i].getNome() << " : " << vetorFunc[i].getSalario() << std::endl;
            verificador = 1;
        }
    }

    if(verificador == 0){
        std::cout << "Nenhum funcionário trabalha neste departamento! " << std::endl;
    }   

    return 0;
}