#include <stdio.h>
#include <Windows.h>

int main(){
    int doLoop = 0, cont = 0;
    int ss[1], mm[1], hh[1];
    printf("Introduzca la hora de inicio: ");
    scanf("%d", hh);
    printf("Introduzca los minutos de inicio: ");
    scanf("%d", mm);
    printf("Introduzca los segundos de inicio: ");
    scanf("%d", ss);
    printf("%d %d : %d %d : %d %d", hh[0], hh[1], mm[0], mm[1], ss[0], ss[1]);
    
    /*do {
        system("clear");
        Sleep(1000);
        cont++;
        printf("%d\n", cont);
    }while(doLoop!=1);
    */
    return 0;
}

//PENDIENTE