#include<stdio.h> 
#include <stdlib.h>
int main() 
{ 
    int tam, *ptr;
    ptr = &tam;
    char arr[tam];
    for(int i = 0; i < 10; i++){
        ptr = (int *)calloc(i,sizeof(char));
        printf("%d\n", tam);
    }
    //printf("Tamaño del arreglo: %d\n", sizeof(arr)/sizeof(char));
} 