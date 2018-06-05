#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double carga( float Vin, float R, float C, float Vo, float t)
{
	//retorno da fun��o de carga do capacitor no cicuito transit�rio RC
	return Vin+(Vo-Vin)*exp(-t/(R*C));
}
void main()
{
	//vari�veis do circu�to
	float Vin, R, C, Vo, t;
	int i;
	//Recep��o de dados	
	printf("Digite a tensao de Entrada, Vin = ");
	scanf("%f",&Vin);
	printf("Digite a Resistencia equivalente, R = ");
	scanf("%f", &R);
	printf("Digite a Capacitancia equivalente, C = ");
	scanf("%f", &C);
	printf("Digite a tensao inicial do capacitor, Vo = ");
	scanf("%f",&Vo);
	//tempo em constantes de tempo
	t=R*C;
	//constru��o da tabela
	printf("\n _________________________________________\n");
	printf("\n Vin = %.3f \t R= %.3f \t C= %.3f \t Vo= %.3f \t ttotal= %.3f \t \n", Vin, R, C, Vo, t*5);
	printf("\n     Tabela de Carga do capacitor pelo tempo\n\n\t _______________________________");
	printf("\n\t|       t\t|       Vc\t|");
	printf("\n\t|_______________|_______________|");
	//la�o de calculo do Vc em fun��o de t
	for(i=0; i<6; i++)
	{
		printf("\n\t| %.4f \t| %.4f \t|", t*i,carga(Vin, R, C, Vo, t*i));
	}
	printf("\n\t|_______________|_______________|\n\n");
}
