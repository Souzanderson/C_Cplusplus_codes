#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

//construtor da matriz de coeficientes
void sistema(int l, int c)
{
	//determinando a matriz tridimensional que forma a estrutura necessaria para a resolucao
	//determinando o vetor das incognitas
	float M[l][l][c]={0}, V[l]={0};
	//contador necessario para iniciar os calculos das matrizes auxiliares
	int cont=1;
			
	//laco de preenchimento da matriz de coeficientes
	for(int i=0; i<l; i++)
	  for(int j=0; j<c; j++ )
	  {
	  	cout<<"M["<<i+1<<"]["<<j+1<<"] = ";
	  	cin>>M[0][i][j];
	  }
	//calculo da reducao do sistema pelo metodo do prof. Adilandri
	while(cont<l)
	{	
		for(int i=0; i<l; i++)
		{
			for(int j=0; j<c; j++)
			{
				//A linha pivo e suas antecessoras devem ser apenas repetidas
				if(i<cont) M[cont][i][j]=M[i][i][j];
				//Algoritmo de preenchimento e calculo do coeficiente pelo método do prof. Adilandri
			    else if(j>=cont) M[cont][i][j]=(M[cont-1][cont-1][cont-1]*M[cont-1][i][j])-(M[cont-1][i][cont-1]*M[cont-1][cont-1][j]);
			}
		}
		cont++;
	}
	cout<<endl;
	//calculo das incognitas 
	for(int i=l-1; i>=0; i--)
	{
		for(int j=c-1; j>=i+1; j--)
		{
			//determinamos qual etapa de calculo estamos e aplicamos o algoritmo de calculo 
			if(j==c-1) V[i]=V[i]+M[cont-1][i][j]/M[cont-1][i][i];
			else V[i]=V[i]-M[cont-1][i][j]*V[j]/M[cont-1][i][i];
		}
	}
	for(int i=0; i<l; i++) 	//exibicao das incognitas
		cout<<"X"<<i+1<<" = "<<V[i]<<endl;
		
	
}

int main()
{
	//variavel que determina o tamanho do sistema
	int i;
	cout<<"Qual a dimensao do sistema? M = ";
	cin>>i;
	cout<<endl;
	//chamada da funcao de resolucao do sistema
	sistema(i,i+1);

	return 0;
}
