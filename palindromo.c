#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char palabra[30];
    int tam = 0, j = 0, last = 0, isPalindromo = 0;
    printf("Este programa esta diseñado para verificar que una palabra o frase es palindroma\n");
    printf("Por favor introduzca su palabra o frase sin considerar espacios: \n");
    scanf("%s", palabra);
    for(int i = 0; i < strlen(palabra); i++){
        if(isalpha(palabra[i])){
            tam++;
        }
    }

    char palabra_ref[tam];
    for (int i = 0; i < tam; i++){
        palabra_ref[i] = palabra[i];
    }

    last = tam - 1;
    while(j < tam && last >= 0){
        if(j != last){
            if(palabra_ref[j] == palabra_ref[last]){
               isPalindromo = 1;
            }else {
                isPalindromo = 0;
            }
        }    
        last--;
        j++;
    }
    printf("La palabra: ");
    for(int i = 0; i < strlen(palabra_ref); i++){
        printf("%c", palabra_ref[i]);
    }
    isPalindromo == 1 ? printf(" es un palindromo\n"): printf(" no es un palindromo\n");
    return 0;
}