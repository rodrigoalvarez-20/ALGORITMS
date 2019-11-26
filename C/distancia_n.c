#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Punto{
    float x;
    float y;
    float r_vect;
    float angulo;
    int distancia[];
} Punto;

void saveDataPoint(float, float, int, Punto[]);
void generateRandomPoints(int, Punto[]);
void displayData(int, Punto[]);
void orderPoints(Punto[]);
void showNearPoints(Punto[]);

int main(){
    srand(time(NULL));
    int cant_puntos = 0, opc_usr;
    Punto *puntos;
    puntos = malloc(cant_puntos*sizeof(Punto));
    system("clear");
    printf("Este programa permite crear manual/automaticamente una serie de puntos ");
    printf("con sus caracteristicas base y calcula los 2 puntos mas cercanos entre todos\n");
    printf("Menu\n");
    printf("1. Manual\n");
    printf("2. Aleatorio\n");
    printf("¿Como desea llenar su arreglo?: ");
    scanf("%d", &opc_usr);
    if (opc_usr == 1){
        int resp = 1;
        while (resp == 1){
            float x,y;
            printf("Introduce la coordenada en X: ");
            scanf("%f", &x);
            printf("Introduce la coordenada en Y: ");
            scanf("%f", &y);
            saveDataPoint(x, y, cant_puntos, puntos);
            printf("¿Desea añadir otro punto? (1 = Si || 0 = No): ");
            scanf("%d", &resp);
            if(resp == 1){
                cant_puntos++;
                puntos = realloc(puntos, cant_puntos);
            }else{
                cant_puntos++;
            }
        }
    }else if(opc_usr == 2){
        printf("¿Cuantos puntos aleatorios?: ");
        scanf("%d", &cant_puntos);
        puntos = realloc(puntos, cant_puntos);
        generateRandomPoints(cant_puntos, puntos);
    }else{
        printf("No es una opcion valida...");
        main();
    }

    printf("Ahora se mostrará la información...\n");
    displayData(cant_puntos, puntos);

    return 0;
}

void saveDataPoint(float x, float y, int index, Punto puntos[]){
    puntos[index].x = x;
    puntos[index].y = y;
    if(x == 0 || y == 0){
        puntos[index].angulo = 0;
        puntos[index].r_vect = 0;
    }else {
        puntos[index].angulo = atan(y/x)*180/3.1416;
        puntos[index].r_vect = (sqrt(pow(puntos[index].x,2)+pow(puntos[index].y,2)));
    }
    printf("%.2f\n", puntos[index].x);
}

void displayData(int size, Punto puntos[]){
    for(int i = 0; i < size; i++){
        printf("Punto #%d\n", i+1);
        printf("Coordenada X:%.2f\n", puntos[i].x);
        printf("Coordenada Y:%.2f\n", puntos[i].y);
        printf("Angulo:%.2f\n", puntos[i].angulo);
        printf("Modulo:%.2f\n", puntos[i].r_vect);
    }
}

void generateRandomPoints(int cant_puntos, Punto puntos[]){
    for(int i = 0; i<cant_puntos; i++){
        float x = rand()%30+1;
        float y = rand()%30+1;
        saveDataPoint(x,y,i,puntos);
    }
}
