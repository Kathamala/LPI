#include <iostream>
//Necessário para saídas no terminal

int main(int argc, char* argv[])
{
    int n1 = 0, n2 = 0;
    //std::cout -> escrever na tela
    //std::cin -> coletar dados do usuário

    std::cout << "Informe o primeiro número: ";
    std::cin >> n1;
    std::cout << "Informe o segundo número: ";
    std::cin >> n2;

    int soma = n1 + n2;
    std::cout << "A soma é: " << soma << std::endl;
    /*Endl quebra a linha, e dá um flush. Ele imprime 
    diretamente no momento do código. Nada executa antes do flush
    terminar (Funciona como uma wait)*/

    return 0;
}