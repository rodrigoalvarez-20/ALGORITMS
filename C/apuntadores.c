#include <stdio.h>

void intercambiando(int *, int *);

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
	printf("V1: %d\n", *v1);
	printf("V2: %d\n", *v2);
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
