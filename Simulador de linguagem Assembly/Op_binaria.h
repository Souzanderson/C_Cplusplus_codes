#ifndef OP_BINARIA_H_INCLUDED
#define OP_BINARIA_H_INCLUDED
#include<iostream>
#include<math.h>
#include <fstream>
//#include<windows.h>

using namespace std;

void Conv_Dec_Bin(int D, int *B, int T);
int Conv_Bin_Dec(int *B, int D, int T);
int Conv_Bin_Dec_IR(int *B, int D, int T);
void Comp_de_dois(int *B, int T);
int Somador_Subtrator(int Ci, int *B1, int *B2, int *S, int T);
int Multiplicador(int *Quoc, int *Mult, int *S, int T);
int Deslocar(int *A, int *Q, int T);
int Deslocar_Esquerda(int* A, int *Q, int T);
int Divisor(int *Quoc, int *Mult, int *S, int *R, int T);
#endif // OP_BINARIA_H_INCLUDED
