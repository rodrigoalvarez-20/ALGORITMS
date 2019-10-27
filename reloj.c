#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
int main(){
    bool isLooping = true;
    int h_1, h_2, m_1, m_2, s_1, s_2, h_Usr, m_Usr, s_Usr;
    //h_1-h_2 : m_1-m_2 : s_1-s_2
    printf("Introduzca la hora de inicio: ");
    scanf("%d", &h_1);
    printf("Introduzca los minutos de inicio: ");
    scanf("%d", &m_1);
    printf("Introduzca los segundos de inicio: ");
    scanf("%d", &s_1);

    printf("Introduzca la hora de termino: ");
    scanf("%d", &h_Usr);
    printf("Introduzca los minutos de termino: ");
    scanf("%d", &m_Usr);
    printf("Introduzca los segundos de termino: ");
    scanf("%d", &s_Usr);

    h_2 = h_1 % 10; h_1 -= h_2; m_2 = m_1 % 10; m_1 /= 10; s_2 = s_1 % 10; s_1 /= 10;

    while(isLooping){
        int hAct = (h_1*10)+h_2;
        int mAct = (m_1*10)+m_2;
        int sAct = (s_1*10)+s_2;
        printf("%d%d : %d%d : %d%d\n", h_1,h_2,m_1,m_2,s_1,s_2);
        sleep(1);
        s_2++;
        if(s_2>9){
            s_1++;
            s_2=0;
        }
        if(s_1>5){
            m_2++;
            s_1=0;
        }
        if(m_2>9){
            m_1++;
            m_2=0;
        }
        if(m_1>5){
            h_2++;
            m_1=0;
        }
        if(hAct == h_Usr && mAct == m_Usr && sAct >= s_Usr && sAct <= (s_Usr+10)){
            printf("\nLa alarma ha sonado\a\n");
        }
    }
    return 0;
}
