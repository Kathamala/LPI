/*
stl -> standard template library (biblioteca padrão de templates)
*reaproveitar códigos da stl pra facilitar. Ex: std::cin, .find(), ...

C++:
1 - Biblioteca padrão do C inteira
2 - Streams de entrada e saída (cin, cout, fstream, ...)
3 - Templates padrão, STL (Contêiners, iteradores, algorítimos)
4 - Bibliotecas avulsas (std::string, exeções, manipulação de memória, ...)

*Contêiner: objeto que armazena objetos. Uma forma de armazenar um conjunto de
dados na memória, ex: array.
- Sequenciais: vector, list, ...
    - Tem um anterior e um próximo;
    - std::vector<T> (Type)
- Associativos: unordered_map, multimap, set, multiset, ...
    - Não sequencial, utiliza uma chave para acessar elementos
    - A ordem inserida não é a mesma da ordem dos elementos
    - std::unordered_map<K, V> (Associar Key a um Value)
- Adaptadores: queue, priorityqueue e stack

*Algorítimos: procedimentos aplicados aos contêiners, ex: ordenar ou buscar 
os elemento.
*Iteradores: generalização de ponteiros que apontam para os elementos do
contêiner. é possível incrementar um iterador e fazer com que ele aponte
para o próximo elemento.
*/
#include <iostream>
#include <vector>
#include <unordered_map> //dicionario
#include <string>
#include <algorithm>

struct Qualquer{

};

int main(int argc, char* argv[]){

    std::vector<int> itens;
    std::vector<Qualquer> itens2;

    itens.push_back(10); //Adicionar itens
    itens.push_back(20);
    itens.push_back(30);    
    itens.push_back(40);    

    std::vector<std::vector<int>> matriz;

    std::cout << itens[0] << std::endl; // Acessar do mesmo jeito de um array normal
    itens.size(); //Tamanho do vector
    itens.capacity(); //Capacidade do vector, também dobra quando chega ao máximo.

    //---------------------------------------------------------------------------
    std::unordered_map<std::string, int> dicionario;
    //Armazenar notas de alunos, por exemplo.
    dicionario["Fulano"] = 10;
    dicionario["Cicrano"] = 8;

    //Iteradores mascaram como iterar uma coleção de objetos
    std::vector<int> numeros;

    numeros.push_back(10);    
    numeros.push_back(20); 
    numeros.push_back(30); 
    numeros.push_back(40); 

    /*
    dicionario.begin();
    dicionario.end();
    numeros.begin();
    numeros.end();
    */
    //Begin aponta para o primeiro elemento, e end aponta pra um espaço depois
    //do último elemento
    for(/* std::vector<int>::iterator */ auto it = numeros.begin(); it != numeros.end(); ++it){
        std::cout << *it << std::endl;
    }
    for(/* std::unordered_map<std::string, int>::iterator */ auto it = dicionario.begin(); it != dicionario.end(); ++it){
        std::cout << it->first << it->second << std::endl; //first é a chave, e second é o valor
    }    
    //Tipo do iterador: std::vector<int>::iterator e std::unordered_map<std::string, int>::iterator
    //auto pega qualquer tipo que a variável seja no iterador.

    std::sort(numeros.begin(), numeros.end()); //algoritimo de ordenação de um vector
    //ranged for loop (C++11 ONLY)
    for(int i : numeros){ //mesma coisa do for acima
        std::cout << i << std::endl;
    }
    for(auto p : dicionario){ // mesma coisa do for acima
        std::cout << p.first << std::endl;
    }

    return 0;
}
/* ATIVIDADE: Utilizar vector;
- mudar o diário para usar um vector ao invés do ponteiro (size e capacity)
- compilar usando vector
- função search, ao inves de retornar um ponteiro para o primeiro, retorna
um vetor de ponteiros com todas as mensagens que contem aquela mensagem.
    std::vector<*Message> search(); -> DECLARAÇÃO
    IMPRIMIR TODAS AS MENSAGENS QUE POSSUEM A PALAVRA
*/