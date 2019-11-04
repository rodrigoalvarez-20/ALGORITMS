/*El siguiente programa le permitir� al usuario simular un retiro de un cajero 
teniendo en consideraci�n la cantidad solicitada deber� ser menor o igual a 12 mil pesos, 
la denominaci�n de billetes sera de 100, 200 y 500, el cajero iniciar� con 600 billetes de 
cada denominaci�n. Se deber� de establecer la forma de entregar lo solicitado al usuario, es decir, 
la cantidad de billetes de cada denominaci�n, asi como llevar un conteo de la cantidad de billetes 
entregados hasta el ultimo movimiento, el retiro deber� de ser mayor o igual al billete de menor 
denominaci�n y multiplo de este*/
#include <stdio.h>
#include <stdbool.h>

int main(){
    bool isMoneyAvailable = true;
    int cant_B_100 = 600, cant_B_200 = 600, cant_B_500 = 600, opc_usr, cant_retiro;
    while (isMoneyAvailable){
        system("clear");
        printf("Menu\n");
        printf("1. Retirar dinero\n");
        printf("2. Consultar retiros\n");
        scanf("%d", &opc_usr);
        switch(opc_usr){
            case 1:
                system("clear");
                printf("Por favor introduzca el monto total a retirar: ");
                scanf("%f", &cant_retiro);
                while(cant_retiro < 100 || cant_retiro > 1200 || cant_retiro % 100 != 0){
                    printf("Por favor introduzca una cantidad multiplo de 100 y menor o igual a 12000 para el retiro\n");
                    printf("Por favor introduzca el monto total a retirar: ");
                    scanf("%f", &cant_retiro);
                }
                
            break;
            case 2:
            break;
        }
    }
}