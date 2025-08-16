#include <stdio.h>
#include <stdlib.h>

int main() {

	char unidade;
	float temperatura;
	float celsiusF , celsiusK, fahrenheitC, fahrenheitK , kelvinC , kelvinF;
	
	printf("Conversor de Temperatura\n");
	printf("Unidade:\n");
	printf("Digite C : Celsius: Converte de Celsius para Fahrenheit e Kelvin\n");
	printf("Digite F : Fahrenheit: Converte de Fahrenheit para Celsius e Kelvin\n");
	printf("Digite K : Kelvin': Converte de Kelvin para Celsius e Fahrenheit\n");
	printf("Digite Abaixo:\n");
	scanf("  %c", &unidade);

	printf("Digite Uma Temperatura Para Converter:\n");
	scanf("%f", &temperatura);
	
	celsiusF = temperatura * 1.8 + 32;
	celsiusK = temperatura + 273;
	fahrenheitC = (temperatura - 32) / 1.8;
	fahrenheitK = ((temperatura - 32) * 5) / 9 + 273;
	kelvinC = temperatura - 273;
	kelvinF = (temperatura - 273) * 1.8 + 32;

	switch (unidade) {
		case 'C':
			printf("A Temperatura Convertida de Celsius Para Fahrenheit e de: %.2f\n", celsiusF);
			printf("A Temperatura Convertida de Celsius Para Kelvin e de: %.2f\n", celsiusK);
			break;

		case 'F':
			printf("A Temperatura Convertida de Fahrenheit Para Celsius e de: %.2f\n", fahrenheitC);
			printf("A Temperatura Convertida de Fahrenheit Para Kelvin e de: %.2f\n", fahrenheitK);
			break;

		case 'K':
			printf("A Temperatura Convertida de Kelvin Para Celsius e de: %.2f\n", kelvinC);
			printf("A Temperatura Convertida de Kelvin Para Fahrenheit e de: %.2f\n", kelvinF);
			break;

		default: printf("Erro Digite Uma Inicial Valida Para Conversao");

	}
	


}