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
void makeOperations(Punto[]);

int main(){
    srand(time(NULL));
    int cant_puntos = 0, opc_usr, resp_op;
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
            cant_puntos++;
            puntos = realloc(puntos, cant_puntos);
            printf("¿Desea añadir otro punto? (1 = Si || 0 = No): ");
            scanf("%d", &resp);
        }
    }else if(opc_usr == 2){
        printf("¿Cuantos puntos aleatorios?: ");
        scanf("%d", &cant_puntos);
        puntos = realloc(puntos, cant_puntos);
        generateRandomPoints(cant_puntos, puntos);
    }else{
        printf("No es una opcion valida...\n");
        main();
    }
    
    printf("Desea realizar alguna operacion con los puntos? ( 1 = Si || 0 = No ): ");
    scanf("%d", &resp_op);
    if(resp_op == 1){
        makeOperations(puntos);
    }

    printf("Ahora se mostrará la información...\n");
    displayData(cant_puntos, puntos);
    //TODO Sacar distancias entre puntos, ordenar de mayor a menor y voila
    //TODO Mostrar la distancia mas corta
    //distancia = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return 0;
}

void saveDataPoint(float x, float y, int index, Punto puntos[]){
    puntos[index].x = x;
    puntos[index].y = y;
    if(x == 0 || y == 0){
        puntos[index].angulo = 0;
        puntos[index].r_vect = 0;
    }else {
        if(x > 0 && y > 0){
            //Cuadrante 1
            puntos[index].angulo = atan(y/x)*180/3.1416;
        }else if(x < 0 && y > 0){
            //Cuadrante 2
            puntos[index].angulo = (atan(y/x)*180/3.1416) + 180;
        }else if(x < 0 && y < 0){
            //Cuadrante 3
            puntos[index].angulo = (atan(y/x)*180/3.1416) + 180;
        }else if(x > 0 && y < 0){
            puntos[index].angulo = (atan(y/x)*180/3.1416) + 360;
        }
        puntos[index].r_vect = (sqrt(pow(puntos[index].x,2)+pow(puntos[index].y,2)));
    }
}

void displayData(int size, Punto puntos[]){
    for(int i = 0; i < size; i++){
        printf("Punto #%d\n", i+1);
        printf("Coordenada X: %.2f\n", puntos[i].x);
        printf("Coordenada Y: %.2f\n", puntos[i].y);
        printf("Angulo: %.2fº\n", puntos[i].angulo);
        printf("Modulo: %.2f\n", puntos[i].r_vect);
    }
}

void generateRandomPoints(int cant_puntos, Punto puntos[]){
    for(int i = 0; i<cant_puntos; i++){
        float x = (rand()%60)-30;
        float y = (rand()%60)-30;
        saveDataPoint(x,y,i,puntos);
    }
}

void makeOperations(Punto puntos[]){
    int resp = 1, index_1, index_2;
    float r_vect, ang;
    Punto p1,p2;
    while(resp == 1){
        int op;
        printf("Menu de operaciones\n");
        printf("1. Sumar Componentes\n");
        printf("2. Restar Componentes\n");
        printf("3. Multiplicar Modulos\n");
        printf("4. Dividir Modulos\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &op);
        printf("Selecciona el primer punto: ");
        scanf("%d", &index_1);
        printf("Selecciona el segundo punto: ");
        scanf("%d", &index_2);
        p1 = puntos[index_1]; p2 = puntos[index_2];
        switch (op){
        case 1:
            printf("(%.2f,%.2f) + (%.2f,%.2f) = %.2f + j%.2f\n", p1.x, p1.y, p2.x, p2.y, (p1.x + p2.x), (p1.y + p2.y));
            break;
        case 2:
            printf("(%.2f,%.2f) - (%.2f,%.2f) = %.2f + j%.2f\n", p1.x, p1.y, p2.x, p2.y, (p1.x - p2.x), (p1.y - p2.y));
            break;
        case 3:
            r_vect = p1.r_vect * p2.r_vect;
            ang = abs(360 - (p1.angulo + p2.angulo));
            printf("%.2f * %.2f = %.2f = %.2fº + %.2fº = %.2f\n", p1.r_vect, p2.r_vect, r_vect, p1.angulo, p2.angulo, ang);
            break;
        case 4:
            r_vect = p1.r_vect / p2.r_vect;
            ang = abs(360 - (p1.angulo - p2.angulo));
            printf("%.2f / %.2f = %.2f = %.2fº - %.2fº = %.2f\n", p1.r_vect, p2.r_vect, r_vect, p1.angulo, p2.angulo, ang);
            break;
        default:
            break;
        }
        printf("¿Desea realizar otra operacion? ( 1 = Si || 0 = No ): ");
        scanf("%d", &resp);
    }
    
}