#ifndef REGISTRADORES_H_INCLUDED
#define REGISTRADORES_H_INCLUDED
#include "Op_binaria.h"
#include "Op_logicas.h"


int MBR[12];
int MAR[12];
int IR[16];
int AC[12];
int OP[4];
int PC;
int MEM[100][16];
//Sets para os registradores
void SetMBR();
void SetMAR();
void SetIR(int E);
void SetMEM(int ini, int fim, int E, int *M);
void SetAC(int *M);
void SetOPCODE();

//Gets dos registradores
void GetMBR(int *M);
void GetMAR(int *M);
void GetIR(int ini, int fim, int *M);
int GetPC();
int GetMEM(int E,int ini, int fim, int *M);
void GetAC(int *M);
int GetOPCODE();

//Operações com registradores
void Load();
void Store();
void ADD();
void SUB();
void MUL();
void AND();
void OR();
void DIV();
void MOD();
void JUMP();
void JUMPZ();
void JUMPN();
void JUMPP();
void INC();
void FIM();



#endif // REGISTRADORES_H_INCLUDED
