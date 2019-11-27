#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define FICHERO "puntos.txt"

typedef struct Distancia{
    int punto;
    float distancia;
}Distancia;

typedef struct Punto{
    float x;
    float y;
    float r_vect;
    float angulo;
    Distancia distancia[];
} Punto;

void showMenu();
void saveDataPoint(float, float, int, Punto[]);
void generateRandomPoints(int, Punto[]);
void displayData(int, Punto[]);
void orderPoints(Punto[]);
void showNearPoints(Punto[]);
void makeOperations(Punto[], int);
int getDataFromFile(Punto[]);
void savePointToFile(Punto);
void getDistances(int, Punto[]);

void showMenu(){
    printf("Menu\n");
    printf("1. Generar puntos manualmente\n");
    printf("2. Generar puntos aleatorios\n");
    printf("3. Sumar puntos\n");
    printf("4. Restar puntos\n");
    printf("5. Multiplicar puntos\n");
    printf("6. Dividir puntos\n");
    printf("7. Imprimir datos de los puntos\n");
    printf("8. Obtener distancia mas corta\n");
    printf("9. Salir\n");
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
        savePointToFile(puntos[index]);
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

void makeOperations(Punto puntos[], int operacion){
    int index_1, index_2, cant_vueltas;
    float r_vect, ang;
    Punto p1,p2;
    printf("Selecciona el primer punto: ");
    scanf("%d", &index_1);
    printf("Selecciona el segundo punto: ");
    scanf("%d", &index_2);
    p1 = puntos[index_1]; p2 = puntos[index_2];
    switch (operacion){
        case 1:
            printf("(%.2f,%.2f) + (%.2f,%.2f) = %.2f + j%.2f\n", p1.x, p1.y, p2.x, p2.y, (p1.x + p2.x), (p1.y + p2.y));
            break;
        case 2:
            printf("(%.2f,%.2f) - (%.2f,%.2f) = %.2f + j%.2f\n", p1.x, p1.y, p2.x, p2.y, (p1.x - p2.x), (p1.y - p2.y));
            break;
        case 3:
            r_vect = p1.r_vect * p2.r_vect;
            ang = fabsf(360 - (p1.angulo + p2.angulo));
            cant_vueltas = ang/360;
            ang -= (ang*cant_vueltas);
            printf("%.2f * %.2f = %.2f = %.2fº + %.2fº = %.2f\n", p1.r_vect, p2.r_vect, r_vect, p1.angulo, p2.angulo, ang);
            break;
        case 4:
            r_vect = p1.r_vect / p2.r_vect;
            ang = fabsf(360 - (p1.angulo - p2.angulo));
            cant_vueltas = ang/360;
            ang -= (ang*cant_vueltas);
            printf("%.2f / %.2f = %.2f = %.2fº - %.2fº = %.2f\n", p1.r_vect, p2.r_vect, r_vect, p1.angulo, p2.angulo, ang);
            break;
        default:
            break;
        }
    
}

int getDataFromFile(Punto puntos[]){
    FILE *fichero;
    fichero = fopen(FICHERO, "r+");
    int size = 0;
    char linea[40], *item;
    if(fichero == NULL){
        printf("Ha ocurrido un error con el archivo\n");
    }else {
        while(fgets(linea, sizeof(linea), fichero) != 0){
            item = strtok(linea, " ");
            int cont = 0;
            while (item != NULL){
                if(cont == 0){
                    //X
                    sscanf(item, "%f", &puntos[size].x);
                }else if(cont == 1){
                    //Y
                    sscanf(item, "%f", &puntos[size].y);
                }else if(cont == 2){
                    //Mod
                    sscanf(item, "%f", &puntos[size].r_vect);
                }else if(cont == 3){
                    //Ang
                    sscanf(item, "%f", &puntos[size].angulo);
                }
                cont++;
                item = strtok (NULL, " ");
            }
            size++;
        }
    }
    fclose(fichero);
    return size;
}

void savePointToFile(Punto puntos){
    FILE *file;
    file = fopen("puntos.txt", "a+");
    fprintf(file, "%.2f %.2f %.2f %.2f\n", puntos.x, puntos.y, puntos.r_vect, puntos.angulo);
    fclose(file);
}

void getDistances(int size, Punto puntos[]){
    for(int i < )
}