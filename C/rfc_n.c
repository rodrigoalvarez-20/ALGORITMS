#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FICHERO "personas.txt"

typedef struct Persona {
    char nombre[20], apPat[20], apMat[20], dia[3], mes[3], anio[5];
}Persona;

int getPersonasFromFile(Persona[]);
void savePersonData(int, Persona[]);
void savePersonDataToFile(Persona);
void displayInfo(int, Persona[]);
void showRFC(Persona);
int showMenu();

int main(){
    Persona *personas;
    int cant_personas = 0, opc_usr;
    personas = malloc(cant_personas*sizeof(Persona));
    do{
        cant_personas = getPersonasFromFile(personas);
        printf("Personas disponibles: %d\n", cant_personas);
        opc_usr = showMenu();
        switch (opc_usr){
        case 1:
            savePersonData(cant_personas, personas);
            cant_personas++;
            personas = realloc(personas, cant_personas);
            break;
        case 2:
            if(cant_personas > 0){
                displayInfo(cant_personas, personas);
            } else {
                printf("No hay ninguna persona disponible\n");
            }
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
    fichero = fopen(FICHERO, "a+");
    rewind(fichero);
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
                    sscanf(item, "%s", personas[size].apPat);
                }else if(cont == 1){
                    //Apellido Materno
                    sscanf(item, "%s", personas[size].apMat);
                }else if(cont == 2){
                    //Nombre
                    sscanf(item, "%s", personas[size].nombre);
                }else if(cont == 3){
                    //Dia 
                    sscanf(item, "%s", personas[size].dia);
                }else if(cont == 4){
                    //Mes
                    sscanf(item, "%s", personas[size].mes);
                }
                else if(cont == 5){
                    //Año
                    sscanf(item, "%s", personas[size].anio);
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

void savePersonData(int index, Persona personas[]){
    int dia, mes, anio;
    char base[] = "0";
    char dia_s[3], mes_s[3], anio_s[5], rfc[11];
    printf("Introduzca su nombre: ");
    scanf("%s", personas[index].nombre);
    printf("Introduzca su apellido paterno: ");
    scanf("%s", personas[index].apPat);
    printf("Introduzca su apellido materno: ");
    scanf("%s", personas[index].apMat);
    printf("Introduzca su dia de nacimiento: ");
    scanf("%d", &dia);
    printf("Introduzca su mes de nacimiento: ");
    scanf("%d", &mes);
    printf("Introduzca su anio de nacimiento: ");
    scanf("%d", &anio);

    if(anio < 1990 && anio > 2019){
        printf("No creo que sea un anio valido...\n");
        printf("Introduzca su anio de nacimiento: ");
        scanf("%d", &anio);
    }
    if(mes == 2 && anio%4 == 0 && dia >29){
        printf("En anio bisiesto, no hay mas de 29 dias\n");
        printf("Introduzca su dia de nacimiento: ");
        scanf("%d", &dia);
    }
    if(mes == 2 && anio%4 != 0 && dia > 28){
        printf("En anio no bisiesto, no hay mas de 28 dias\n");
        printf("Introduzca su dia de nacimiento: ");
        scanf("%d", &dia);
    }
    if((dia > 31 || dia < 1) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10  || mes ==11 )){
        printf("No es un dia valido\n");
        printf("Introduzca su dia de nacimiento: ");
        scanf("%d", &dia);
    }
    if(dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
        printf("No es un dia valido\n");
        printf("Introduzca su dia de nacimiento: ");
        scanf("%d", &dia);
    }
    if(dia < 1){
        printf("No es un dia valido\n");
        printf("Introduzca su dia de nacimiento: ");
        scanf("%d", &dia);
    }
    if(mes > 12 || mes < 1){
        printf("No es un mes valido\n");
        printf("Introduzca su mes de nacimiento: ");
        scanf("%d", &mes);
    }

    if(dia > 9){
        sprintf(dia_s, "%d", dia);
    }else {
        sprintf(dia_s, "%s%d", base, dia);
    }
    if(mes > 9){
        sprintf(mes_s, "%d", mes);
    }else {
        sprintf(mes_s, "%s%d", base, mes);
    }
    sprintf(anio_s, "%d", anio);
    
    strncpy(personas[index].dia, dia_s, 3);
    strncpy(personas[index].mes, mes_s, 3);
    strncpy(personas[index].anio, anio_s, 5);

    savePersonDataToFile(personas[index]);
    
}

void savePersonDataToFile(Persona persona){
    FILE *file;
    file = fopen(FICHERO, "a+");
    fprintf(file, "%s %s %s %s %s %s\n", persona.apPat, persona.apMat, persona.nombre, persona.dia, persona.mes, persona.anio);
    fclose(file);
}

void displayInfo(int size, Persona personas[]){
    int opc_usr, index;
    printf("Menu\n");
    printf("1. Mostrar todos los registros\n");
    printf("2. Seleccionar registro\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc_usr);
    switch (opc_usr){
        case 1:
            for(int i = 0; i < size; i++){
                printf("Persona #%d:\n", i+1);
                printf("%s %s %s %s/%s/%s\n", personas[i].apPat, personas[i].apMat, personas[i].nombre, personas[i].dia, personas[i].mes, personas[i].anio);
                showRFC(personas[i]);
            }
        break;
        case 2:
            printf("Personas disponibles: %d\n", size);
            printf("Seleccione una persona: ");
            scanf("%d", &index);
            printf("Persona #%d:\n", index+1);
            printf("%s %s %s %s/%s/%s\n", personas[index-1].apPat, personas[index-1].apMat, personas[index-1].nombre, personas[index-1].dia, personas[index-1].mes, personas[index-1].anio);
            showRFC(personas[index-1]);
        break;
    }
}

void showRFC(Persona persona){
    char rfc[11];
	rfc[0] = toupper(persona.apPat[0]);
	rfc[1] = toupper(persona.apPat[1]);
	rfc[2] = toupper(persona.apMat[0]);
	rfc[3] = toupper(persona.nombre[0]);
	rfc[4] = toupper(persona.anio[2]);
	rfc[5] = toupper(persona.anio[3]);
	rfc[6] = toupper(persona.mes[0]);
	rfc[7] = toupper(persona.mes[1]);
	rfc[8] = toupper(persona.dia[0]);
	rfc[9] = toupper(persona.dia[1]);
    rfc[10] = '\0';
    printf("RFC: %s\n", rfc);
}