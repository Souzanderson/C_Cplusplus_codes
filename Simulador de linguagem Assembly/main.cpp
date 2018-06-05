#include <iostream>
#include "Interface.cpp"

using namespace std;

int main()
{
    //Inicia o programa buscando o codigo no arquivo e salvando em um vetor
    LerArquivo();
    //o vetor é transferido para a matriz de memória
    SalvarMem();
    //o menu principal do programa é chamado
    Menu();
    return 0;
}
