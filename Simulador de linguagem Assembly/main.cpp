#include <iostream>
#include "Interface.cpp"

using namespace std;

int main()
{
    //Inicia o programa buscando o codigo no arquivo e salvando em um vetor
    LerArquivo();
    //o vetor � transferido para a matriz de mem�ria
    SalvarMem();
    //o menu principal do programa � chamado
    Menu();
    return 0;
}
