#include <stdio.h>
int main(){
    int f0 = 0, f1 = 1, fn = 0, lim = 0, cont = 0, opc;
    printf("Este es un programa para calcular la serie Fibonacci en base a un limite dado por el usuario\n");
    printf("Introduzca el valor limite a calcular: ");
    scanf("%d",&lim);
    printf("Modo de calculo\n");
    printf("1)Do-While\n2)While\n3)For\n");
    printf("Introduzca el modo deseado: ");
    scanf("%d", &opc);
    switch (opc){
        case 1:
            /* Seccion DO-WHILE */
            if(lim>0){
                do{
                    cont <= lim ? printf("%d,", fn) : printf("%d", fn);
                    //printf("%d, %d\n", cont, lim);
			        f0 = f1;
			        f1 = fn;
			        fn = f0 + f1;
			        cont++;
                }while(cont<=(lim+1));
            }else {
                printf("El limite debe de ser mayor que 0\n");
            }   
        break;
        case 2:
            /* Seccion WHILE */
            if(lim>0){
                while(cont<=(lim+1)){
                    cont <= lim ? printf("%d,", fn) : printf("%d", fn);
			        f0 = f1;
			        f1 = fn;
			        fn = f0 + f1;
			        cont++;
                }
            }else {
                printf("El limite debe de ser mayor que 0\n");
            }   
        break;
        case 3:
            /* Seccion For */
            if(lim>0){
                for(int i = 0; i <= lim+1; i++){
                    i <= lim ? printf("%d,", fn) : printf("%d", fn);
			        f0 = f1;
			        f1 = fn;
			        fn = f0 + f1;
                }
            }else {
                printf("El limite debe de ser mayor que 0\n");
            }   
        break;
        default:
            printf("No selecciono una opcion valida");
        break;
    }
}