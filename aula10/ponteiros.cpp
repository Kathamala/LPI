//Ponteiros HaHaHaHaHaHa!
/*
Adress Of (&) -> retorna o endereço de memória de uma variável
    int a = 10;
    int *b = &a; "b recieve Adress Of a"

Dereferência (*) -> acessa ou modifica uma posição de memória
    std::cout << *b << std::endl; "é printado o valor que está no endereço b"
    *b = 20; "o valor que está no endereço b passa a ser 20, ou seja, a = 20"

Ponteiro nulo -> b = nullptr; ou b = 0;

Referência (&) -> outros nomes que damos para a mesma posição de memória
    int &joaozinho = joao; "joaozinho é um apelido, se chamar joaozinho, joao olha"
    joaozinho = 20; "fazendo isso, joao = 20"



void por_copia(int a){
    a = 30;
}
void por_referencia(int& a){
    a = 30;
}
void por_ponteiro(int* a){
    if(a != nullptr){
        *a = 40;
    }
}
int n = 10;
por_copia(n) -> no fim, n = 10
por_referencia(n) -> no fim, n = 30
por_ponteiro(&n) -> no fim, n = 40



int arr[] = {10, 20, 30, 40}; -> arr é um ponteiro para o primeiro elemento do array
std::cout << *arr << std::endl; -> printa 10
std::cout << *(arr+1) << std::endl; -> printa 20



struct MyStruct{
    int variable;
    void funcao(){

    }
    void calcular(int variable);
}
MyStruct::calcular(int variable){
    this->variable = variable; "this é um ponteiro que aponta para a propria instancia do struct"
}

int main(){
    MyStruct s;
    s.variable = 10;
    s.funcao();

    MyStruct *p = &s;
    p->variable = 20; "-> e o simbolo de dereferencia de struct. Ou (*p).variable = 20;
    p->funcao();
}

ERROS:

1 - Checar se o ponteiro não aponta pra nulo quando tentar dereferenciar
int main(){
    int *p = nullptr;
    //500 linhas de código
    *p = 100; -> ERRO
}

2 - Usar ponteiros desalocados
int main(){
    int *p = new int;
    delte p;
    //500 linhas de codigo
    std::cout << *p << std::endl; -> ERRO
}

3 - Alocar memoria temporária
int main(){
    int a = 10;
    { int b = 20; } -> b só existe dentro dessas chaves
    std::cout << b << std::endl; -> ERRO
}

4 - retornar endereços de variaveis locais
int get_pointer(){
    int a;

    return &a;
}
int main(){
    int *a = get_pointer();
    *a = 30; -> a só existe dentro da get_pointer. ERRO
}

ATIVIDADE: No diário, adicionar uma nova função no app.
./diary search <argumento>

retornar, através de ponteiros, um ponteiro pra PRIMEIRA mensagem que encontrar que tem
essa palavra. Printar "Encontrado!".
Se não existir, retorna nullptr
find => passa um valor, e verifica se esse valor existe na string

Message* search(std::string what){

}



*/