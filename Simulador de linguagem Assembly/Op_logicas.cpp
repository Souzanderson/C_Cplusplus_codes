#include "Op_logicas.h"

//And l�gico entre dois bin�rios e salvo em um terceiro bin�rio S de tamanho T
void modand(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if (B1[i]==1 && B2[i]==1) S[i]= 1;
        else S[i]=0;
    }
}
//Or l�gico entre dois bin�rios e salvo em um terceiro bin�rio S de tamanho T
void modor(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if (B1[i]==1 || B2[i]==1) S[i]  = 1;
        else S[i] =0;
    }
}
//xor l�gico entre dois bin�rios e salvo em um terceiro bin�rio S de tamanho T
void modxor(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if(B1[i]!= B2[i]) S[i]  = 1;
        else S[i] =0;
    }
}
//xnor l�gico entre dois bin�rios e salvo em um terceiro bin�rio S de tamanho T
void modxnor(int* B1, int* B2, int* S, int T)
{
    for(int i=T-1; i>=0; i--)
    {
        if (B1[i]== B2[i]) S[i]  = 1;
        else S[i] =0;
    }
}
