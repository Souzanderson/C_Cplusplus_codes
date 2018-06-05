#include "Op_binaria.h"
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

//Converte números binários em decimais
//O primeiro parâmetro recebe o vetor com o número binário
//O segundo parâmetro recebe a variável que recebe o resultado em binário
//O terceiro parâmetro consiste no número de bits do binário
int Conv_Bin_Dec(int* B, int D, int T)
{
    D=0;
    int flag;
    if(B[0]==1)
    {
        Comp_de_dois(B,T);
        flag=-1;
    }
    int e=0;
    for(int i=T-1; i>=0; i--)
    {
        D=D+B[i]*pow(2,e);
        e++;
    }
    if(flag==-1) return D*(-1);
    else return D;
}

//Este conversor segue a mesma logica do anterior, porém ignora o sinal do binário
int Conv_Bin_Dec_IR(int *B, int D, int T)
{
    D=0;
    int e=0;
    for(int i=T-1; i>=0; i--)
    {
        D=D+B[i]*pow(2,e);
        e++;
    }
    return D;
}

//Converte decimais para binário
//O primeiro parâmetro é o decimal que será convertido
//O segundo parâmetro o vetor que receberá o resultado em binário
//o terceiro parâmetro é o tamanho do vetor ou número de bits do binário
void Conv_Dec_Bin(int D, int* B,int T)
{
    int flag=0;
    if(D<0)
    {
        D=D*(-1);
        flag=-1;
    }
    for(int i=T-1; i>=0; i--)
    {
        if(D==0) B[i]=0;
        if(D==1)
        {
            B[i]=1;
            D=0;
        }
        else if(D%2==0)
        {
            B[i]=0;
            D=D/2;
        }
        else if(D%2==1)
        {
            B[i]=1;
            D=D/2;
        }
    }
    if(flag==-1)
    {
        Comp_de_dois(B,T);
    }
}

//realiza o complemento de dois do binário
//o primeiro parâmetro é o vetor de binários
//o segundo parâmetro o tamanho do vetor ou número de bits do binário
void Comp_de_dois(int* B,int T)
{
    int C[T];
    int S[T];
    int flag=0;

    for(int i=0; i<T; i++)
    {
        if(i!=T-1) C[i]=0;
        else C[i]=1;
    }

    if(B[0]==0 || B[0]==1)
    {
        for(int i=0; i<T; i++)
        {
            if(B[i]==0) B[i]=1;
            else B[i]=0;
        }
        flag=Somador_Subtrator(0,B,C,S,T);
        if(flag!= -1) for(int x=0; x<T; x++) B[x] = S[x];
        else cout<<"\nOverflow detectado! Complemento impossivel!"<<endl;
    }
}

//Realiza operações de soma ou subtração, se ci=0 realiza soma, se ci=1 subtração
//primeiro parâmetro Ci, indica soma ou subtração
//segundo parâmetro é o primeiro binário para somar com o segundo
//terceiro parâmetro é o segundo binário a somar com o primeiro
//quarto parâmetro indica o resultado da soma
//quinto parâmetro o número de bits para se trabalhar
int Somador_Subtrator(int Ci, int* B1, int* B2, int* S, int T)
{
    int Co=0;
    if(Ci==0)
    {
        for(int i=T-1; i>=0; i--)
        {
            if(Ci==0)
            {
                if(B1[i]+B2[i]==0)
                {
                    S[i]=0;
                    Co=0;
                }
                else if(B1[i]+B2[i]==1)
                {
                    S[i]=1;
                    Co=0;
                }
                else
                {
                    S[i]=0;
                    Co=1;
                }
            }
            else
            {
                if(B1[i]+B2[i]==0)
                {
                    S[i]=1;
                    Co=0;
                }
                else if(B1[i]+B2[i]==1)
                {
                    S[i]=0;
                    Co=1;
                }
                else
                {
                    S[i]=1;
                    Co=1;
                }
            }
            if(i!=0) Ci=Co;
        }
        if (Ci==Co) return 0;
        else return -1;
    }
    else
    {
        Comp_de_dois(B2,T);
        Ci=0;
        for(int i=T-1; i>=0; i--)
        {
            //cin=1; N1=0; N2=0;
            if(Ci==0)
            {
                if(B1[i]+B2[i]==0)
                {
                    S[i]=0;
                    Co=0;
                }
                else if(B1[i]+B2[i]==1)
                {
                    S[i]=1;
                    Co=0;
                }
                else
                {
                    S[i]=0;
                    Co=1;
                }
            }
            else
            {
                if(B1[i]+B2[i]==0)
                {
                    S[i]=1;
                    Co=0;
                }
                else if(B1[i]+B2[i]==1)
                {
                    S[i]=0;
                    Co=1;
                }
                else
                {
                    S[i]=1;
                    Co=1;
                }
            }
            if(i!=0) Ci=Co;
        }
        if (Ci==Co) return 0;
        else
        {
            cout<<"\nOverflow detectado! Soma/Subtração impossível!"<<endl;
            exit(-1);
            return -1;
        }
    }
}
//realiza a multiplicação de dois números
//O primeiro parâmetro indica o quociente de multiplicação (multiplicador)
//O segundo parâmetro indica o multiplicando
//O terceiro parâmetro é o vetor onde será guardado o resultado da multiplicação
//O quarto parâmetro indica o tamanho do vetor ou número de bits do resultado
int Multiplicador(int* Quoc, int* Mult, int* S, int T)
{
    int A[T], K=0, CM[T], Q[T], M[T], cont=T;
    for(int i=0; i<T; i++)
    {
        M[i]=Mult[i];
        Q[i]=Quoc[i];
        CM[i]=M[i];
        A[i]=0;
    }
    Comp_de_dois(CM,T);
    do
    {
        if(K!=Q[T-1])
        {
            if(Q[T-1]==1 && K==0)
            {
                Somador_Subtrator(0,A,CM,A,T);
            }
            else Somador_Subtrator(0,A,M,A,T);
            K=Deslocar(A,Q,T);
        }
        else
        {
            K=Deslocar(A,Q,T);
        }
        cont--;
    }
    while(cont!=0);
    for(int x=0; x<T; x++) S[x]=Q[x];
    return 0;
}

//realiza o deslocamento da multiplicação a direita
int Deslocar(int* A, int* Q, int T)
{
    int flag = Q[T-1];
    for(int i=T-1; i>0; i--)
    {
        Q[i]=Q[i-1];
    }
    Q[0]=A[T-1];
    for(int i=T-1; i>0; i--)
    {
        A[i]=A[i-1];
    }
    return flag;
}
//Realiza a divisão sem sinal de dois binários
//o primeiro parâmetro recebe o binário que será o quociente da divisão
//o segundo parâmetro recebe o binário que será o dividendo da divisão
//o terceiro parâmetro é o vetor que recebe o resultado em binário
//o quarto parâmetro recebe o resto em binário da divisão
//o quinto parâmetro indica o número de bits da operação
int Divisor(int *Quoc, int *Mult, int *S,int *R, int T)
{
    int A[T], CM[T], Q[T], M[T], B[T], cont=T, flag=1, aux;
    for(int i=0; i<T; i++)
    {
        M[i]=Mult[i];
        Q[i]=Quoc[i];
        CM[i]=Mult[i];
        A[i]=0;
        B[i]=0;
    }
    Comp_de_dois(CM,T);

    aux=Conv_Bin_Dec(M,aux,T);
    if(aux<0) flag=flag*(-1);
    aux=Conv_Bin_Dec(Q,aux,T);
    if(aux<0) flag=flag*(-1);

DESLOCAMENTO:

    Deslocar_Esquerda(A,Q,T);
    for(int i=0; i<T; i++) B[i]=A[i];

    if(A[0]==M[0]) Somador_Subtrator(0,A,CM,A,T);
    else  Somador_Subtrator(0,A,M,A,T);

    if(A[0]==B[0]) Q[11]=1;
    else for(int i=0; i<T; i++) A[i]=B[i];

    cont--;
    if(cont!=0) goto DESLOCAMENTO;

    if(flag==0) Comp_de_dois(Q,T);

    for(int i=0; i<T; i++)
    {
        S[i]=Q[i];
        R[i]=A[i];
    }
    return 0;
}
//deslocamento a esquerda da divisão
int Deslocar_Esquerda(int* A, int *Q, int T)
{
    int i;
    for(i=0; i<T-1; i++)
        A[i]=A[i+1];
    A[T-1]=Q[0];
    for(i=0; i<T-1; i++)
        Q[i]=Q[i+1];
    Q[T-1]=0;
    int flag = A[0];
    return flag;
}
