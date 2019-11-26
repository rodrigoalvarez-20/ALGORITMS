#include <stdio.h>
#include <ctype.h>
#include <string.h>
void getRFC(char[],char[],char[], char[], char[], char[]);

int main(){
	char nombre[20], apPat[20], apMat[20], dia[3], mes[3], anio[5], base[] = "0";
	int dia_i, mes_i, an_i;
	printf("Este programa sirve para calcular el RFC de una persona\n");
	printf("Introduce tu nombre: ");
	scanf("%s", nombre);
	printf("Introduce tu apellido paterno: ");
	scanf("%s", apPat);
	printf("Introduce tu apellido materno: ");
	scanf("%s", apMat);
	printf("Introduce tu dia de nacimiento: ");
	scanf("%d", &dia_i);
	printf("Introduce tu mes de nacimiento: ");
	scanf("%d", &mes_i);
	printf("Introduce tu anio de nacimiento: ");
	scanf("%d", &an_i);
	
	if(dia_i > 9){
        sprintf(dia, "%d", dia_i);
    }else {
        sprintf(dia, "%s%d", base, dia_i);
    }
    if(mes_i > 9){
        sprintf(mes, "%d", mes_i);
    }else {
        sprintf(mes, "%s%d", base, mes_i);
    }
    sprintf(anio, "%d", an_i);
	getRFC(nombre, apPat, apMat, dia, mes, anio);
	return 0;
}

void getRFC(char nombre[20], char apPat[20] , char apMat[20], char dia[2], char mes[2], char anio[4]){
	char rfc[10];
	rfc[0] = toupper(apPat[0]);
	rfc[1] = toupper(apPat[1]);
	rfc[2] = toupper(apMat[0]);
	rfc[3] = toupper(nombre[0]);
	rfc[4] = toupper(anio[2]);
	rfc[5] = toupper(anio[3]);
	rfc[6] = toupper(mes[0]);
	rfc[7] = toupper(mes[1]);
	rfc[8] = toupper(dia[0]);
	rfc[9] = toupper(dia[1]);
	printf("Los datos ingresados son: \n");
	printf("Nombre: %s\n", nombre);
	printf("Apellidos: %s %s\n", apPat, apMat);
	printf("Fecha de nacimiento: %s/%s/%s\n", dia,mes,anio);
	printf("El RFC es: %s\n", rfc);

}
