#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    srand(time(NULL));
    int cont = 20, opc = 0, trans = 0;
    int vals[cont];
    printf("Este es un programa para llenar un arreglo de 20 espacios por medio de una forma manual o una forma aleatoria\n");
    printf("1. Manual\n2. Aleatorio\n");
    printf("¿Como desea llenar el arreglo?: ");
    scanf("%d", &opc);
    switch (opc){
        case 1:
            for(int i = 0; i < cont; i++){
                printf("Introduce el valor #%d: ", (i+1));
                scanf("%d", &vals[i]);
            }
        break;
        case 2:
            for(int i = 0; i < cont; i++){
                vals[i] = rand()%100;
            }
        break;
        default:
            printf("No es una opcion valida\n");
        break;
    }
    printf("\nMostrando el arreglo desordenado...\n");

    for(int i=0; i<cont; i++){
        int aux = i;
        aux++ == cont ? printf("%d", vals[i]) : printf("%d, ", vals[i]);
    }
    
    printf("\nOrdenando...\n");
    for (int i = 0; i < cont; i++){
        for (int j = 0; j < cont; j++){
            if(vals[i] < vals[j]){
                trans = vals[i];
				vals[i] = vals[j];
				vals[j] = trans;
            }
        }
    }

    printf("\nMostrando arreglo ordenado:\n");
    
    for(int i=0; i<cont; i++){
        int aux = i;
        aux++ == cont ? printf("%d", vals[i]) : printf("%d, ", vals[i]);
    }
}
