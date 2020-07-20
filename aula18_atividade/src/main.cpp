#include <iostream>

#include "../include/conta.hpp"
#include "../include/fila.hpp"
#include "../include/gerente.hpp"
#include "../include/caixa.hpp"
#include "../include/seguranca.hpp"

int main(){

    gerente g;
    caixa c;
    seguranca s1;
    seguranca s2;
    clientePF cl;

    g.setIdade(47);
    g.setNome("Ricardo Henrique");
    g.setSalario(5056.76);

    c.setIdade(34);
    c.setNome("Carlos Fagner");
    c.setSalario(2043.53);    

    s1.setIdade(38);
    s1.setNome("Adelbert Steiner");
    s1.setSalario(1700.52);    

    s2.setIdade(39);
    s2.setNome("Woll Rodriguez");
    s2.setSalario(1750.00);   

    cl.setIdade(23);
    cl.setNome("Framboesa de Titânio");
    cl.setSexo("Masculino"); 

    std::cout << g.getNome() << std::endl;
    std::cout << c.getNome() << std::endl;
    std::cout << s1.getNome() << std::endl;
    std::cout << s2.getNome() << std::endl;
    std::cout << cl.getNome() << std::endl;
    return 0;
}