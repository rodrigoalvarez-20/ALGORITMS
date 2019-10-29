#include <stdio.h>
int main(){
    int nNum=0, nNum_Temp=0, cont = 0, nEspacio=0;
    printf("Este programa tiene como finalidad realizar la conversion de un numero en base decimal, dado por el usuario\n");
    printf("Introduce el numero a convertir: ");
    scanf("%d", &nNum);
    nNum_Temp = nNum;

    while(nNum_Temp >= 1){
        nNum_Temp = nNum_Temp / 2;
		nEspacio++;
    }
    
    int binario[nEspacio];
    nNum_Temp = nNum;

    while(nNum_Temp>=1){
        binario[cont] = nNum_Temp % 2;
        nNum_Temp = nNum_Temp / 2;
        cont++;
    }
    cont--;

    printf("Al numero %d en base 10, le corresponde un valor de: ", nNum);
	while(cont>=0){
        printf("%d",binario[cont]);
        cont--;
    }

	printf(" en binario\n");
    return 0;
}