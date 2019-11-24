#include <stdio.h>
#include <math.h>
int main(){
    int fr_1, fr_2, fr_4, fr_3;
    printf("Este programa sirve para calcular el nivel de resistividad en base a un codigo introducido por el usuario\n");
    printf("Menu\n");
    printf("0 -- Negro\n");
    printf("1 -- Cafe\n");
    printf("2 -- Rojo\n");
    printf("3 -- Naranja\n");
    printf("4 -- Amarillo\n");
    printf("5 -- Verde\n");
    printf("6 -- Azul\n");
    printf("7 -- Violeta\n");
    printf("8 -- Gris\n");
    printf("9 -- Blanco\n");
    printf("Introduce el valor de la primer franja: ");
    scanf("%d", &fr_1);
    printf("Introduce el valor de la segunda franja: ");
    scanf("%d", &fr_2);
    printf("Introduce el valor de la tercer franja: ");
    scanf("%d", &fr_3);
    printf("Seleccione un color para la cuarta franja:\n0 -- Dorado\n1 -- Plata\n");
    scanf("%d", &fr_4);
    fr_3 = pow(10, fr_3);
    fr_3 *= fr_2;
    printf("%d%d ohm %c ", fr_1,fr_3, 241);
    fr_4 == 0 ? printf("5\%%\n") : printf("10\%%\n");	
    return 0;
}