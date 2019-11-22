#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Persona{
    char nombre[20];
    char apellidoPat[20];
    char apellidoMat[20];
    char diaNac[3];
    char mesNac[3];
    char anNac[5];
    char RFC[11];
};

void savePersonData(struct Persona[], int);
void showRFCs(struct Persona[], int);

int main(){
    int i = 0;
    struct Persona *personas;
    personas = (struct Persona *)malloc(i*sizeof(struct Persona));
    int resp = 1;
    printf("Este programa permite calcular el RFC de 'n' cantidad de personas\n");
    while (resp == 1){
        savePersonData(personas, i);
        i++;
        personas = (struct Persona *)realloc(personas, i);
        printf("¿Desea agregar otra persona? (1 = Si || 0 = No): ");
        scanf("%d", &resp);
    }
    printf("Ahora se mostrarán los datos...\n");
    showRFCs(personas, i);
    free(personas);
}

void savePersonData(struct Persona personas[], int index){
    int dia, mes, anio;
    char base[] = "0";
    char dia_s[3], mes_s[3], anio_s[5], rfc[11];
    printf("Introduzca su nombre: ");
    scanf("%s", personas[index].nombre);
    printf("Introduzca su apellido paterno: ");
    scanf("%s", personas[index].apellidoPat);
    printf("Introduzca su apellido materno: ");
    scanf("%s", personas[index].apellidoMat);
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
    if(mes == 2 && dia > 28){
        printf("Febrero no tiene mas de 28 dias...\n");
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
    
    strncpy(personas[index].diaNac, dia_s, 3);
    strncpy(personas[index].mesNac, mes_s, 3);
    strncpy(personas[index].anNac, anio_s, 5);

    rfc[0] = toupper(personas[index].apellidoPat[0]);
	rfc[1] = toupper(personas[index].apellidoPat[1]);
	rfc[2] = toupper(personas[index].apellidoMat[0]);
	rfc[3] = toupper(personas[index].nombre[0]);
	rfc[4] = toupper(personas[index].anNac[2]);
	rfc[5] = toupper(personas[index].anNac[3]);
	rfc[6] = toupper(personas[index].mesNac[0]);
	rfc[7] = toupper(personas[index].mesNac[1]);
	rfc[8] = toupper(personas[index].diaNac[0]);
	rfc[9] = toupper(personas[index].diaNac[1]);
    rfc[10] = '\0';

    strncpy(personas[index].RFC, rfc, 11);
}

void showRFCs(struct Persona personas[], int final_size){
    for(int i = 0; i<final_size; i++){
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Apellidos: %s %s\n", personas[i].apellidoPat, personas[i].apellidoMat);
        printf("Dia de nacimiento: %s\n", personas[i].diaNac);
        printf("Mes de nacimiento: %s\n", personas[i].mesNac);
        printf("Anio de nacimiento: %s\n", personas[i].anNac);
        printf("RFC: %s\n", personas[i].RFC);
    }
}