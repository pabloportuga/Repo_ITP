#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clubes{
    char nome[100];
    int marcados, sofridos;
} Time;



int main(){
    Time melhor = {0};
    Time h;
    int mudou = 0;
    char temp1[100];
    int temp, temp2;
    int n, i;
    Time times[100] = {0};
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf(" %[^\n]", times[i].nome);
        scanf("%d\n%d", &times[i].marcados, &times[i].sofridos);
    }

    do{
        mudou = 0;
        for(i=1; i < n; i++){
            if(times[i-1].marcados < times[i].marcados){
                temp = times[i].marcados;
                times[i].marcados = times[i-1].marcados;
                times[i-1].marcados = temp;

                strcpy(temp1, times[i].nome);
                strcpy(times[i].nome, times[i-1].nome);
                strcpy(times[i-1].nome, temp1);

                temp2 = times[i].sofridos;
                times[i].sofridos = times[i-1].sofridos;
                times[i-1].sofridos = temp2;

                mudou = 1;
            }
        }
    }while(mudou == 1);

    for(i=0;i<n;i++){
        printf("%d - %s\nGols marcados: %d\nGols sofridos: %d\n", i+1, times[i].nome, times[i].marcados, times[i].sofridos);
    }
    return 0;
}
