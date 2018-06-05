#include "Op_logicas.h"

//And lógico entre dois binários e salvo em um terceiro binário S de tamanho T
void modand(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if (B1[i]==1 && B2[i]==1) S[i]= 1;
        else S[i]=0;
    }
}
//Or lógico entre dois binários e salvo em um terceiro binário S de tamanho T
void modor(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if (B1[i]==1 || B2[i]==1) S[i]  = 1;
        else S[i] =0;
    }
}
//xor lógico entre dois binários e salvo em um terceiro binário S de tamanho T
void modxor(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if(B1[i]!= B2[i]) S[i]  = 1;
        else S[i] =0;
    }
}
//xnor lógico entre dois binários e salvo em um terceiro binário S de tamanho T
void modxnor(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if (B1[i]== B2[i]) S[i]  = 1;
        else S[i] =0;
    }
}
