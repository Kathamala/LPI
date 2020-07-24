/*
Capturar erros ocorridos durante a excução do programa. A ideia é não 
interromper a execução do programa por causa de um erro.

throw(xxx), onde xxx = contrutor da classe para qual está sendo lançada a exceção.

try/catch;

try{ //inicio do bloco TRY
    if(n == 0){
        throw  (TrataDivZero(__LINE__)); // o throw, quando executado, dá um break;
        //Passa o número da linha onde o erro ocorreu
    }
    cout << "Divisao " << (double)n/m << endl;

}

catch(TrataDivZero){ //só executa se o try for executado
    T.Msg();
}

- Exceções Padronizadas:
catch (bad_alloc E){
    cout << "Faltou memória!" << endl;
}
*/