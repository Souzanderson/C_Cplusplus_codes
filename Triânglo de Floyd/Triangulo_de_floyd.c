#include<stdio.h>

void main()
{
	//variaveis
	int i,j;
	//for que controla a linha
	for(i=1; i<9; i++)
		//for que controla a coluna (i<=j)
		for(j=1; j<=i; j++)
		{
			//exibindo o termo atraves da formula Aij=[(i-1)*i/2]+j
			printf("%d",(i-1)*i/2+j);
			//se chegar ao fim da linha dar um salto
			(j==i)?printf("\n"):printf("\t");
		}		
}
