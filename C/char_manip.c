#include <stdio.h>
#include <ctype.h>

int main(){
    char texto_orig[50];
    int cant_A = 0, cant_E = 0, cant_I = 0, cant_O = 0, cant_U = 0, cant_palabras = 1, tam = 0, i_start_pal_2 = 0, i_start_pal_3 = 0;
    printf("Este programa tiene como finalidad determinar el numero de palabras ");
    printf("cantidad de vocales y recorte de posicion en base a un texto introducido por el usuario\n");
    printf("Introduce el texto a analizar: \n");
    scanf("%[^\n]", texto_orig);
    for (int i = 0; i<50; i++){
        if(texto_orig[i] != '\0'){
            tam++;
        }else{
            break;
        }
    }
    char texto_filtrado[tam];
    for(int i = 0; i<tam; i++){
        texto_filtrado[i] = texto_orig[i];
    }
    for(int i = 0; i < tam; i++){
        if(tolower(texto_filtrado[i]) == 'a'){
            cant_A++;
        }else if(tolower(texto_filtrado[i]) == 'e'){
            cant_E++;
        }else if(tolower(texto_filtrado[i]) == 'i'){
            cant_I++;
        }else if(tolower(texto_filtrado[i]) == 'o'){
            cant_O++;
        }else if(tolower(texto_filtrado[i]) == 'u'){
            cant_U++;
        }else if(texto_filtrado[i] == ' ' && texto_filtrado[i-1] != ' '){
            if(cant_palabras == 1){
                i_start_pal_2 = i+1;
            }
            if(cant_palabras == 2){
                i_start_pal_3 = i+1;
            }
            cant_palabras++;
        }
    }

    printf("El texto original es: \n");
    for(int i = 0; i<tam; i++){
        printf("%c", texto_filtrado[i]);
    }
    printf("\nCantidad de palabras: %d\n", cant_palabras);
    printf("Cantidad de A: %d\n", cant_A);
    printf("Cantidad de E: %d\n", cant_E);
    printf("Cantidad de I: %d\n", cant_I);
    printf("Cantidad de O: %d\n", cant_O);
    printf("Cantidad de U: %d\n", cant_U);
    if(cant_palabras == 2){
        printf("Arreglo recortado: \n");
        for (int i = 0; i < i_start_pal_2; i++){
            printf("%c", texto_filtrado[i]);
        }
    }else if(cant_palabras > 2 ){
        printf("Arreglo recortado: \n");
        int tam_pal_3 = tam - i_start_pal_3;
        int salto = i_start_pal_3 - i_start_pal_2;
        for (int i = 0; i < tam; i++){
            if(i >= i_start_pal_2 && i < i_start_pal_2 + tam_pal_3){
                texto_filtrado[i] = texto_filtrado[i + salto];
                texto_filtrado[i + salto] = '\0';
            }
            if(texto_filtrado[i] != '\0'){
                printf("%c", texto_filtrado[i]);
            }
        }
    }else {
        printf("No se puede realizar el recorte\n");
    }
    return 0;
}