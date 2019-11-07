//Mi primer apuntador 
/*
El siguiente programa recibira del usuario 2 variables enteras y utilizando una funcion que llamaremos 'intercambiando', rcibiremos como parametro
2 apuntadores hacia las variables recibidas e intercambiaremos sus valores mediante una variable de memoria temporal local. Imprimiremos los valores originales,
los valores en la funcion y los valores despues de
*/

#include <stdio.h>

void intercambiando(int *val1, int *val2);

int main(){
	int *v1,*v2, V1,V2;
	printf("Este programa es el primero de manipulacion de punteros. Intercambia 2 valores\n");
	printf("Introduzca el valor de V1: ");
	scanf("%d",&V1);
	printf("Introduzca el valor de V2: ");
	scanf("%d",&V2);
	v1 = &V1;
	v2 = &V2;
	printf("Antes de la funcion: \n");
	printf("V1: %d\n", V1);
	printf("V2: %d\n", V2);
	intercambiando(v1,v2);
	printf("Saliendo de la funcion: \n");
	printf("V1: %d\n", *v1);
	printf("V2: %d\n", *v2);
}

void intercambiando(int *val1, int *val2){
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
	printf("En la funcion: \n");
	printf("V1: %d\n", *val1);
	printf("V2: %d\n", *val2);
}
