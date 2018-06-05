#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

//construtor da matriz de coeficientes
void determinante(int l, int c)
{
	float M[l][l][c];
	for(int a=0; a<l; a++)
		for(int i=0; i<l; i++)
			for(int j=0; j<c; j++) M[a][i][j]=0;
	
	
	for(int i=0; i<l; i++)
	  for(int j=0; j<c; j++ )
	  {
	  	cout<<"M["<<i+1<<"]["<<j+1<<"] = ";
	  	cin>>M[0][i][j];
	  }
	int cont=1;
	while(cont<l)
	{	
		for(int i=0; i<l; i++)
		{
			for(int j=0; j<c; j++)
			{
				if(i<cont) M[cont][i][j]=M[i][i][j];
			    else if(j>=cont) M[cont][i][j]=((M[cont-1][cont-1][cont-1]*M[cont-1][i][j])-(M[cont-1][i][cont-1]*M[cont-1][cont-1][j]))/M[cont-1][cont-1][cont-1];
			}
		}
		cont++;
	}
	float valor=1;
	for(int i=0; i<l; i++)
	{
		valor=valor*M[cont-1][i][i];
	}
	cout<<endl<<"Det(M) = "<<valor<<endl;
}

int main()
{
		//variavel que determina o tamanho do sistema
	int i;
	cout<<"Qual a dimensao do determinante? D = ";
	cin>>i;
	cout<<endl;
	//chamada da funcao de resolucao do sistema
	determinante(i,i);
	cin>>i;
	return 0;
}
