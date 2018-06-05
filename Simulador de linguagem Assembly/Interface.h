#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "Op_binaria.h"
#include "Op_logicas.h"
#include "Registradores.cpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#include<string.h>


using namespace std;

int linha=0;
string Arquivo[50];
//ciclo unico de leitura
void LerArquivo();
void SalvarMem();

//ciclo de execução
int IniciarExec();
void InterpretarLinha(int E);
void MostrarMemoria(int tipo);
int Menu();
void GuardarMemoriaArquivo();


#endif // INTERFACE_H_INCLUDED
