//Mi RFC
//Utilizando una funcion deberemos de obtener el RFC de una persona bajo el sig. esquema
//Solicitar apellidos, nombre y la fecha de nacimiento a conveniencia de una persona en Mexico
//El resultado a la salida de la funcion sera los datos antes mencionados junto con el RFC
#include <stdio.h>
#include <ctype.h>
//Nombre, ApellidoPat, ApellidoMat, Dia, Mes, Año
void getRFC(char[],char[],char[], char[], char[], char[]);

int main(){
	char nombre[20], apPat[20], apMat[20];
	char dia[2], mes[2], anio[4];
	printf("Este programa sirve para calcular el RFC de una persona\n");
	printf("Introduce tu nombre: ");
	scanf("%s", nombre);
	fflush(stdin);
	printf("Introduce tu apellido paterno: ");
	scanf("%s", apPat);
	fflush(stdin);
	printf("Introduce tu apellido materno: ");
	scanf("%s", apMat);
	fflush(stdin);
	printf("Introduce tu dia de nacimiento en formato '00': ");
	scanf("%s", dia);
	fflush(stdin);
	printf("Introduce tu mes de nacimiento en formato '00': ");
	scanf("%s", mes);
	fflush(stdin);
	printf("Introduce tu anio de nacimiento: ");
	scanf("%s", anio);
	fflush(stdin);
	printf("%s %s %s %s/%s/%s", nombre, apPat, apMat,dia,mes,anio);
	//getRFC(nombre, apPat, apMat, dia, mes, anio);
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
