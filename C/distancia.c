#include <stdio.h>
#include <math.h>
int main(){
    float x1,y1,x2,y2,pendiente, distancia, r_vector_1, r_vector_2, angulo_1, angulo_2;
    printf("Este programa esta diseñado para calcular la distancia entre 2 puntos con coordenadas dadas por el usuario, asi como la pendiente, ecuacion de la recta, radio vector y angulo\n");
    printf("Introduce la coordenada X1: ");
    scanf("%f",&x1);
    printf("Introduce la coordenada Y1: ");
    scanf("%f",&y1);
    printf("Introduce la coordenada X2: ");
    scanf("%f",&x2);    
    printf("Introduce la coordenada Y2: ");
    scanf("%f",&y2);    
    pendiente = (y2-y1)/(x2-x1);
    distancia = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    r_vector_1 = (sqrt(pow(x1,2)+pow(y1,2)));
    r_vector_2 = (sqrt(pow(x2,2)+pow(y2,2)));
    angulo_1 = tan(y1/x1);
    angulo_2 = tan(y2/x2);
    printf("El punto A tiene las coordenadas: (%.2f,%.2f)\n", x1,y1);
    printf("El punto B tiene las coordenadas: (%.2f,%.2f)\n", x2,y2);
    printf("La distancia entre el punto A y B es: %.2f\n", distancia);
    printf("La pendiente de la recta es: %.2f\n", pendiente);
    float temp = (pendiente*-x1) + y1;
    printf("La ecuacion donde podemos encontrar los puntos A y B es: y=%.2f*X", pendiente);
    temp >= 0 ? printf(" + %.2f\n", temp) : printf("%.2f\n",temp);
    printf("\t************\n");
    printf("El radio vector de X1 - Y1 es de: %.2f\n", r_vector_1);
    printf("El radio vector de X2 - Y2 es de: %.2f\n", r_vector_2);
    printf("El angulo de X1 - Y1 es de: %.2f\n", angulo_1);
    printf("El angulo de X2 - Y2 es de: %.2f\n", angulo_2);
    return 0;
}