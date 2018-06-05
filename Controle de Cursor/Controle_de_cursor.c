#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void posicionar(int x, int y, const char c)
{
	static int X=0;
	static int Y=0;
	int i,j;
	X=X+x;
	Y=Y+y;
	if(Y<0) Y=0;
	if(X<0) X=0;

	system("cls");
	for(j=0; j<Y; j++) printf("\n");
	for(i=0; i<X; i++) printf(" ");
	
	printf("%c",c);
}

void loop()
{
	int c;
	posicionar(0,0,'0');
	inicio:
	c=0;	
	c=getch();
	
	switch(c)
	{
		case 72: posicionar(0,-1,'0');
				  //printf("Cima!\n");
				  goto inicio;
				  break;
		case 80: posicionar(0,1,'0');
				  //printf("Baixo!\n");
				  goto inicio;
				  break;
		case 75:  posicionar(-1,0,'0');
				  //printf("Esquerda!\n");
				  goto inicio;
				  break;
		case 77: posicionar(1,0,'0');
				  //printf("Direita!\n");
				  goto inicio;
				  break;
		case 27: printf("\n____________________________ \n########GAME OVER!#########\n");
				  break;
	    default: goto inicio;
	}
}

void main()
{
	loop();
}
