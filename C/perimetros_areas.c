#include <stdio.h>
int main(){
	float area, per, lado, base, altura, radio, base_2, apotema, pi = 3.14;
	int opc;
	printf("Este es un programa para calcular el area y perimetro en base a la figura que elija el usuario\n");
	printf("Menu: \n1) Circulo\n2) Cuadrado\n3) Rectangulo\n4) Pentagono\n5) Triangulo\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &opc);
	switch(opc){
        case 1:
			printf("Introduce el valor del radio:");
			scanf("%f", &radio);
			area = pi * radio * radio;
			per = pi * (radio * 2);
            break;
		case 2:
			printf("Introduce el valor del lado: ");
			scanf("%f", &lado);
			area = lado * lado;
			per = lado * 4;
            break;
		case 3:
			printf("Introduce el valor de la base: ");
			scanf("%f", &base);
			printf("Introduce el valor de la altura: ");
			scanf("%f", &altura);
			area = base * altura;
			per = (2 * base) + (2 * altura);
            break;
		case 4:
			printf("Introduce el valor de la base: ");
			scanf("%f", &base);
			printf("Introduce el valor de la apotema: ");
			scanf("%f", &apotema);
			per = base * 5;
			area = per * apotema;
            break;
		case 5:
			printf("Introduce el valor de las bases iguales: ");
			scanf("%f", &base);
			printf("Introduce el valor de la base desigual: ");
			scanf("%f", &base_2);
			printf("Introduce el valor de la altura: ");
			scanf("%f", &altura);
			per = (2 * base) + base_2;
			area = (base * altura)/2;
            break;
    default:
        printf("No ha seleccionado una opcion valida\n");
        break;
    } 
		
	if(opc >= 1 && opc<= 5){
        printf("El area es: %.2f\n", area);
		printf("El perimetro es: %.2f", per);
    }
	
    return 0;
}