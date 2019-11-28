#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FICHERO "personas.txt"

typedef struct Persona {
    char nombre[20], apPat[20], apMat[20], dia[3], mes[3], anio[5];
}Persona;

int getPersonasFromFile(Persona[]);
void savePersonData(int, Persona);
void showRFCs(int, Persona[]);
int showMenu();

int main(){
    Persona *personas;
    int cant_personas = 0, opc_usr;
    personas = malloc(cant_personas*sizeof(Persona));
    cant_personas = getPersonasFromFile(personas);
    do{
        opc_usr = showMenu();
        switch (opc_usr){
        case 1:
            //Añadir usuario
            break;
        case 2: 
            //Mostrar RFCs
            break;
        default:
            break;
        }
    }while(opc_usr != 3);
    free(personas);
    return 0;
}

int getPersonasFromFile(Persona personas[]){
    FILE *fichero;
    fichero = fopen(FICHERO, "r+");
    int size = 0;
    char linea[100], *item;
    if(fichero == NULL){
        printf("Ha ocurrido un error con el archivo\n");
    }else {
        while(fgets(linea, sizeof(linea), fichero) != 0){
            item = strtok(linea, " ");
            int cont = 0;
            while (item != NULL){
                if(cont == 0){
                    //Apellido Paterno
                    sscanf(item, "%s", &personas[size].apPat);
                }else if(cont == 1){
                    //Apellido Materno
                    sscanf(item, "%s", &personas[size].apMat);
                }else if(cont == 2){
                    //Nombre
                    sscanf(item, "%s", &personas[size].nombre);
                }else if(cont == 3){
                    //Dia 
                    sscanf(item, "%s", &personas[size].dia);
                }else if(cont == 4){
                    //Mes
                    sscanf(item, "%s", &personas[size].mes);
                }
                else if(cont == 5){
                    //Año
                    sscanf(item, "%s", &personas[size].anio);
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

int showMenu(){
    int opc;
    printf("Menu\n");
    printf("1. Agregar una nueva persona\n");
    printf("2. Mostrar RFCs\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

