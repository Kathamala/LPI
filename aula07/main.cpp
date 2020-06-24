#include <iostream>
#include <string>

int main(int argc, char* argv[]){
/*Alocar 5 gigas de memória (5368709128)
    char* memory = new char(5 gigas);
    delete[] memory;
    memory = nullptr; -> Usar isso  depois do delete, para evitar o acesso
                         a memória vazia.

    Alocar (malloc) -> new
    Desalocar (free) -> delete

    int *a = new int; -> 4 bytes alocados na memória heap
    float *f = new float; -> Tambem aloca 4 bytes

    std::cout << a << std::endl; -> retorna o endereço de memória alocado para a

    delete a; -> realmente necessário dessa vez,
    delete f; -> para não vazar memória
    ***para cada new, deve ter um delete***

    size_t size = 1000;
    int *numbers = new int[size];


    Quando o espeço alocado é esgotado, criamos uma nova variavel com mais
    espaço, movemos o conteúdo para ela, e depois excluimos a primeira.
    
    Message *m = new Message;
    Message *messages = new Message[1000];
    Message *messages2 = new Message[2000];

    -> Mover o conteudo de messages para messages2

    delete[] messages;
    messages = messages2;
*/
    return 0;

    /*Atividade: fazer método add adicionar uma mensagem no 
    array de mensagens, alocado dinamicamente (Diary.cpp).

    Escolher valor incial, e adicionar mensagens até esse tamanho.
    Ex: 10 mensagens, add 10 mensagens, ok!

Diary::diary (): ..., messages(nullptr){
    messages = new messages?
}
    iniciar message size como 0, e message capacity como 10

    */
}