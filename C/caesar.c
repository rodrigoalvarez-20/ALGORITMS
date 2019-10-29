#include <stdio.h>
#include <ctype.h>
int main(){
    int priv_key=0, sizeArr = 0, opc;
    char val_usr[100];
    printf("Este programa tiene como finalidad crear un sistema de Cifrado utilizando el algoritmo \"Cesar\"");
    printf(" basandose en la definicion del usuario de la llave. (Solamente caracteres numericos)\n");
    printf("Por favor introduzca el valor de la llave privada: ");
    scanf("%d", &priv_key);
    if(priv_key >= 10){
        int temp = priv_key / 2;
        priv_key = priv_key - (priv_key*temp);
    }
    printf("Menu de opciones\n");
    printf("1) Codificar texto\n");
    printf("2) Decodificar texto\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);

    switch(opc){
        case 1: {
            printf("Introduzca el texto a codificar: ");
            scanf("%s", val_usr);
            for(int i = 0; i<100; i++){
                if(isdigit(val_usr[i])){
                    sizeArr++;
                }
            }
            char dataStr[sizeArr];
            int data_Convert[sizeArr];
            for(int i = 0; i<sizeArr; i++){
                int val = val_usr[i]-48;
                dataStr[i] = val_usr[i];
                val += priv_key;
                if(val>=10){
                    val -=10;
                }
                data_Convert[i] = val;
            }
            printf("El texto original es: ");
            for(int i = 0; i < sizeArr; i++){
                printf("%c", dataStr[i]);
            }
            printf(". Y el texto codificado es: ");
            for(int i = 0; i < sizeArr; i++){
                printf("%d", data_Convert[i]);
            }
        }
        break;
        case 2: {
            printf("Introduzca el texto a decodificar: ");
            scanf("%s", val_usr);
            for(int i = 0; i<100; i++){
                if(isdigit(val_usr[i])){
                    sizeArr++;
                }
            }
            char dataStr_2[sizeArr];
            int data_Convert_2[sizeArr];
            for(int i = 0; i<sizeArr; i++){
                int val = val_usr[i]-48;
                dataStr_2[i] = val_usr[i];
                val -= priv_key;
                if(val<0){
                    val = 10 + val;
                }
                data_Convert_2[i] = val;
            }
            printf("El texto original es: ");
            for(int i = 0; i < sizeArr; i++){
                printf("%c", dataStr_2[i]);
            }
            printf(". Y el texto decodificado es: ");
            for(int i = 0; i < sizeArr; i++){
                printf("%d", data_Convert_2[i]);
            }
        }
        break;
    }

}