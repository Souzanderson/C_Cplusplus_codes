#include "Registradores.h"

//realiza o salvamento do velor especificado de mem�ria no MBR
void SetMBR()
{
    int valor=Conv_Bin_Dec(MAR,valor,12);
    for(int i=0; i<12; i++) MBR[i]=MEM[valor][i+4];
}
//raliza a transfer�ncia dos 12 bits de endere�o ou dado do IR para o MAR
void SetMAR()
{
    for(int i=0; i<12; i++) MAR[i]=IR[i+4];
}
//busca o IR na matriz de mem�ria
void SetIR(int E)
{
    for(int i=0; i<16; i++) IR[i]=MEM[E][i];
}
//realiza uma escrita na mem�ria na posi��o especificada
// ini indica o inicio da coluna, fim o fim da coluna, E � o endere�o ou linha de mem�ria
// M indica o vetor que ser� transferido para a mem�ria (o tamanho � definido entre ini e fim)
void SetMEM(int ini, int fim, int E, int* M)
{
    int a=0;
    for(int i=ini; i<fim; i++)
    {
        MEM[E][i]=M[a];
        a++;
    }
}
//transfere um valor para o registrador AC
void SetAC(int* M)
{
    for(int i=0; i<12; i++) AC[i]=M[i];
}
//Permite escrever um OPCODE no IR
void SetOPCODE()
{
    for(int i=0; i<4; i++) OP[i]=IR[i];
}
//Busca o valor do acumulador AC
void GetAC(int* M)
{
    for(int i=0; i<12; i++) M[i]=AC[i];
}
//Busca o valor salvo no MBR
void GetMBR(int* M)
{
    for(int i=0; i<12; i++) M[i]=MBR[i];
}
//Busca o valor do registrador MAR
void GetMAR(int* M)
{
    for(int i=0; i<12; i++) M[i]=MAR[i];
}
//busca o valor do registrador IR (pode-se definir partes especificas usando ini e fim)
void GetIR(int ini, int fim,int* M)
{
    for(int i=ini; i<fim; i++) M[i]=IR[i];
}
//Busca o contador do programa PC
int GetPC()
{
    return PC;
}
//busca uma posi��o especifica de mem�ria, podendo-se especificar coluna (ini e fim) e linha (E)
int GetMEM(int E, int ini, int fim, int* M)
{
    int a=0;
    for(int i=ini; i<fim; i++)
    {
        M[a]=MEM[E][i];
        a++;
    }

    return E;
}
//busca o OPCODE de uma instru��o no IR
int GetOPCODE()
{
    int valor=Conv_Bin_Dec_IR(IR,valor,4);
    return valor;
}
//Realiza a opera��o de LOAD
void Load()
{
    SetAC(MBR);
    PC++;
}
//Realiza a opera��o de STOR
void Store()
{
    int valor=Conv_Bin_Dec(MAR,valor,12);
    for(int i=0; i<12; i++) MEM[valor][i+4]=AC[i];
    PC++;
}
//Realiza a opera��o de ADD
void ADD()
{
    Somador_Subtrator(0,AC,MBR,AC,12);
    PC++;
}
//Realiza a opera��o de SUB
void SUB()
{
    Somador_Subtrator(1,AC,MBR,AC,12);
    PC++;
}
//Realiza a opera��o de MUL
void MUL()
{
    Multiplicador(AC,MBR,AC,12);
    PC++;
}
//realiza a opera��o de DIV
void DIV()
{
    int R[12];
    int S[12];
    GetAC(S);
    GetMBR(R);
    Divisor(S,R,S,R,12);
    SetAC(S);
    PC++;
}
//Realiza a opera��o de MOD (restaura o resto da divis�o)
void MOD()
{
    int S[12];
    Divisor(AC,MBR,S,AC,12);
    PC++;
}
//opera��o AND
void AND()
{
    modand(AC,MBR,AC,12);
    PC++;
}
//Realiza a opera��o OR
void OR()
{
    modor(AC,MBR,AC,12);
    PC++;
}
//Realiza a opera��o JUMP sem condi��o
void JUMP()
{
    PC=Conv_Bin_Dec(MAR,PC,12);
}
//Realiza o JUMPZ condicional AC = 0
void JUMPZ()
{
    int aux=Conv_Bin_Dec(AC,aux,12);
    if(aux==0) PC=Conv_Bin_Dec(MAR,PC,12);
    else PC++;
}
//Realiza o JUMPN condicional AC <0
void JUMPN()
{
    int aux=Conv_Bin_Dec(AC,aux,12);
    if(aux<0) PC=Conv_Bin_Dec(MAR,PC,12);
    else PC++;
}
//realiza o JUMPP condicional AC>0
void JUMPP()
{
    int aux=Conv_Bin_Dec(AC,aux,12);
    if(aux>0) PC=Conv_Bin_Dec(MAR,PC,12);
    else PC++;
}
//Aumenta o AC em 1
void INC()
{
    int A[12]= {0,0,0,0,0,0,0,0,0,0,0,1},v[12];
    Somador_Subtrator(0,AC,A,v,12);
    SetAC(v);
    PC++;
}
//Essa fun��o n�o faz nada
void FIM()
{
    PC=-1;
}
