#include <stdio.h>
int main(){
    int ec[3][2], pendiente = 0;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            if(j==0){
                printf("\nIntroduzca el valor de X%d: ", (i+1));
            }else{
                printf("\nIntroduzca el valor de Y%d: ", (i+1));
            } 
            scanf("%d", &ec[i][j]);
        }
    }
    //printf("X1: %d, Y1: %d\n", ec[0][0], ec[0][1]);
    //printf("X2: %d, Y2: %d\n", ec[1][0], ec[1][1]);
    ec[0][2] = (ec[1][1] - ec[1][0])/(ec[0][1] - ec[0][0]);
    //printf("Pendiente: %d\n", ec[0][2]);
    printf("La ecuacion de la recta en su forma y=mx + b es:\n");
    printf("\t y = %d*%d + %d\n", ec[0][2], ec[0][0], ec[0][1]);

    return 0;
}