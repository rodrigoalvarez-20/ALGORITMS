#include <stdio.h>
#include <ctype.h>
int main(){
    char color[8];
    printf("Este programa tiene como finalidad mostrar un mensaje\ndescriptivo en base a un color del semaforo introducido por el usuario\n");
    printf("Introduce el color (como texto): ");
    scanf("%s", color);
    if(tolower(color[0]) == 'r' && tolower(color[1]) == 'o' && tolower(color[2]) == 'j'){
        printf("El color rojo significa que se detenga\n");
    }else if(tolower(color[0]) == 'a' && tolower(color[1]) == 'm' && tolower(color[2]) == 'a'){
        printf("El color amarillo significa que reduzca la velocidad\n");
    }else if(tolower(color[0]) == 'v' && tolower(color[1]) == 'e' && tolower(color[2]) == 'r'){
        printf("El color verde significa que puede pasar\n");
    }else {
        printf("No ha introducido un color valido\n");
    }
    return 0;
}