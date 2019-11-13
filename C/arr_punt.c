#include <stdio.h>
int main(){
    int arr[2][3], *point, val;
    point = &arr[0][0];
    for(int i = 0; i < 6; i++){
        printf("Introduce un valor: ");
        scanf("%d", &val);
        *point = val;
        point++;
    }
    printf("Mostrando los valores...\n");
    point = &arr[0][0];
    for(int i = 0; i < 6; i++){
        printf("Valor #%d: %d\n", i+1,*point);
        point++;
    }
}