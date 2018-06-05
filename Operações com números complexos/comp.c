//Software destinado para realizar multiplicação e divisão de complexos
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//separa a parte inteira da parte imaginária
lecomp(char a[], float *z)
{
	char real[100]="";
	char imag[100]="";
	int i=0, j=0, flag=1;
	float r, im;
	
	do
	{
		//verficação de sinal da parte inteira
		if(a[j]=='-')
		{
			flag=-1;
			j++;
		}
		//atribui o valor 
		real[i]=a[j];
		if(a[j+1]=='-' || a[j+1]=='+' ) break;
		i++;
		j++;
	}while(1);
	
	real[i+1]='\0';
	r=atof(real);
	r=r*flag;
	i=0;
	j+=2;
	if(a[j-1]=='-') flag=-1;
	else flag=1;
	
	do
	{
		imag[i]=a[j];
		if(a[j+1]=='j' || a[j+1]=='i' ) break;
		i++;
		j++;
	}while(1);
	
	imag[i+1]='\0';
	im=atof(imag);
	im=im*flag;
	z[0]=r;
	z[1]=im;
}

//realiza a operação com os números complexos e a operação escolhida passados por parâmetro
opcomp(float *z1, float *z2, float *z, int op)
{
	switch(op)
	{
		//multiplicação de complexos
		case 1: z[0]=z1[0]*z2[0]-z1[1]*z2[1]; 
				z[1]=z1[0]*z2[1]+z1[1]*z2[0];
				printf("Z = [(%.3f)+(%.3f)j] x [(%.3f)+(%.3f)j]\n",z1[0],z1[1],z2[0],z2[1]);
				break;
		//divisão de complexos
		case 2: z[0]=(z1[0]*z2[0]+z1[1]*z2[1])/(z2[0]*z2[0]+z2[1]*z2[1]);
				z[1]=(z1[1]*z2[0]-z1[0]*z2[1])/(z2[0]*z2[0]+z2[1]*z2[1]);
				printf("Z = [(%.3f)+(%.3f)j] %/ [(%.3f)+(%.3f)j]\n",z1[0],z1[1],z2[0],z2[1]);
				break;
		//soma de complexos
		case 3: z[0]=z1[0]+z2[0];
				z[1]=z1[1]+z2[1];
				printf("Z = [(%.3f)+(%.3f)j] + [(%.3f)+(%.3f)j]\n",z1[0],z1[1],z2[0],z2[1]);
				break;
		//subtração de complexos
		case 4: z[0]=z1[0]-z2[0];
				z[1]=z1[1]-z2[1];
				printf("Z = [(%.3f)+(%.3f)j] - [(%.3f)+(%.3f)j]\n",z1[0],z1[1],z2[0],z2[1]);
		default: break;
	}
}

void main()
{
	//exemplo de uso das operacões
	float z1[2], z2[2], z[2];
	lecomp("2+3j", z1);
	printf("Z1 = (%.3f)+(%.3f)j\n",z1[0],z1[1]);
	lecomp("3+5j", z2);
	printf("Z2 = (%.3f)+(%.3f)j\n",z2[0],z2[1]);
	opcomp(z1,z2,z,1);
	printf("resultado= (%.2f)+(%.2f)j\n", z[0], z[1]);
	opcomp(z1,z2,z,2);
	printf("resultado= (%.4f)+(%.4f)j\n", z[0], z[1]);
	opcomp(z1,z2,z,3);
	printf("resultado= (%.2f)+(%.2f)j\n", z[0], z[1]);
	opcomp(z1,z2,z,4);
	printf("resultado= (%.2f)+(%.2f)j\n", z[0], z[1]);
}

