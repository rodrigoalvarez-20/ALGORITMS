#include <stdio.h>
int main(void){
    int n1,n2,n3, nUsr, prod;
    char opc;
    system("cls");
    printf("Este programa calcula el producto de los 3 numeros mayores introducidos por el usuario\n");
    printf("Introduce el primer valor: ");
    scanf("%d",&n1);
    printf("Introduce el segundo valor: ");
    scanf("%d",&n2);
    printf("Introduce el tercer valor: ");
    scanf("%d",&n3);
    printf("¿Desea agregar un nuevo valor? s/n \n");
    scanf("%s",&opc);
    while (opc == 's') {
        printf("Introduce el valor: ");
        scanf("%d",&nUsr);
        if(n1<n2&&n1<n3&&n1<nUsr){
            n1=nUsr;
        }else if(n2<n1&n2<n3&&n2<nUsr){
	        n2=nUsr;
        }else if(n3<n1&&n3<n2&&n3<nUsr){    
	        n3=nUsr;
        }
        printf("�Desea agregar un nuevo valor? s/n \n");
        scanf("%s",&opc);
    }
    prod = n1*n2*n3;
    printf("El producto es: %d", prod);
    return 0;
}