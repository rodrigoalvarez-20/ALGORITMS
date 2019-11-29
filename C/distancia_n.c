#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
    srand(time(NULL));
    int cant_puntos = 0, opc_usr, add_point, cant_temp;
    Punto *puntos;
    puntos = malloc(cant_puntos*sizeof(Punto));
    cant_puntos = getDataFromFile(puntos);
    system("clear");
    printf("Este programa permite crear manual/automaticamente una serie de puntos ");
    printf("con sus caracteristicas base y calcula los 2 puntos mas cercanos entre todos\n");
    do {
        printf("Puntos actuales: %d\n", cant_puntos);
        showMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opc_usr);
        switch (opc_usr){
        case 1:
            //Manual
            do {
                float x,y;
                printf("Introduce la coordenada en X: ");
                scanf("%f", &x);
                printf("Introduce la coordenada en Y: ");
                scanf("%f", &y);
                saveDataPoint(x, y, cant_puntos, puntos);
                cant_puntos++;
                puntos = realloc(puntos, cant_puntos);
                printf("¿Desea añadir otro punto? (1 = Si || 0 = No): ");
                scanf("%d", &add_point);
            }while(add_point == 1);
            break;
        case 2:
            //Aleatorios
            printf("¿Cuantos puntos aleatorios?: ");
            scanf("%d", &cant_temp);
            cant_puntos += cant_temp;
            puntos = realloc(puntos, cant_puntos);
            generateRandomPoints(cant_puntos, puntos);
            break;
        case 3:
            //Suma
            if(cant_puntos >= 2){
                makeOperations(puntos, 1);
            }else{
                printf("No hay cantidad suficiente de puntos\n");
            }
            break;
        case 4:
            //Resta
            if(cant_puntos >= 2){
                makeOperations(puntos, 2);
            }else{
                printf("No hay cantidad suficiente de puntos\n");
            }
            break;
        case 5:
            //Mult
            if(cant_puntos >= 2){
                makeOperations(puntos, 3);
            }else{
                printf("No hay cantidad suficiente de puntos\n");
            }
            break;
        case 6:
            //Div
            if(cant_puntos >= 2){
                makeOperations(puntos, 4);
            }else{
                printf("No hay cantidad suficiente de puntos\n");
            }
            break;
        case 7:
            //Datos
            if(cant_puntos > 0){
                displayData(cant_puntos, puntos);
            }else{
                printf("No hay cantidad suficiente de puntos\n");
            }
            break;
        case 8:
            //Ordenamiento y menor
            if(cant_puntos >= 2){
                getDistances(cant_puntos, puntos);
            }else{
                printf("No hay cantidad suficiente de puntos\n");
            }
            break;
        case 9:
            if(remove(FICHERO) == 0){
                printf("Se ha eliminado correctamente\n");
            }
            break;
        default:
            exit(1);
            break;
        }
    }while(opc_usr >=1 && opc_usr <= 10);
    free(puntos);
    return 0;
}