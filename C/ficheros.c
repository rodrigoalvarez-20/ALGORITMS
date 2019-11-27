#include <stdio.h>
#include <string.h>
int main(){
    FILE *file;
    file = fopen("puntos.txt", "r+");
    char linea[40], *item;
    if(file == NULL){
        printf("Ha ocurrido un error con el archivo\n");
    }else {
        while(fgets(linea, sizeof(linea), file) != 0){
            //printf("%s", linea);
            item = strtok(linea, " ");
            int cont = 0;
            while (item != NULL){
                if(cont == 0){
                    printf("X: ");
                }else if(cont == 1){
                    printf("Y: ");
                }else if(cont == 2){
                    printf("RVect: ");
                }else if(cont == 3){
                    printf("Angulo: ");
                }
                printf ("%s ", item);
                cont++;
                item = strtok (NULL, " ");
                
            }
        }
    }
    fclose(file);
    
    return 0;
}