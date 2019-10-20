#include <stdio.h>
int main(){
    int tam, mcd = 1, isMCD_1 = 0;
    
    printf("Este programa tiene como finalidad obtener el MCD entre una serie de numeros introducidos por el usuario\n");
    printf("¿Cuantos numeros desea ingresar?: ");
    scanf("%d", &tam);
    if(tam < 2){
        printf("Por favor, introduzca de 2 en adelante\n");
        printf("¿Cuantos numeros desea ingresar?: ");
        scanf("%d", &tam);
    }
    int valores[tam];
    for(int i=0; i< tam; i++){
        printf("Introduce el valor: ");
        scanf("%d", &valores[i]);
    }
    printf("Ordenando...\n");
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            if(valores[i] < valores[j]){
                int trans = valores[i];
				valores[i] = valores[j];
				valores[j] = trans;
            }
        }
    }
    printf("Calculando MCD\n");

    for(int i = 2; i <= valores[tam-1]; i++){
        for(int j = 0; j < tam; j++){
            if(valores[j] % i != 0){
                isMCD_1 = 1;
                break;
            }else {
                isMCD_1 = 0;
            }
        }
        if(isMCD_1 != 1){
            mcd = i;    
        }
    }
    
    printf("El mcd es: %d", mcd);

}