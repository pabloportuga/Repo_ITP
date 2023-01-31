#include <stdio.h>

typedef struct Smartphone{
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]){
    int i = qnt_cadastrada;
    scanf(" %[^\n]s", phones[i].modelo);
    scanf("%d\n%f\n%f\n%f\n", &phones[i].memoria, &phones[i].processador, &phones[i].camera, &phones[i].bateria);
    return i;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin){
    int count = 0;
    for(int i = 1; i< qnt_cadastrada;i++){
        if(phones[i].memoria>=reqMin.memoria && phones[i].processador>=reqMin.processador && phones[i].camera>=reqMin.camera && phones[i].bateria>=reqMin.bateria){
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\nProcessador: %.2fGhz\nCamera: %.2fMPixels\nBateria: %.2fmA\n\n", phones[i].memoria, phones[i].processador, phones[i].camera, phones[i].bateria);
            count++;
        }
    }
    printf("%d smartphones encontrados.", count);
    return count;
}
int main(){
    Smartphone phones[100] = {0};
    char resposta = 's';
    int i = 1;
    while(resposta == 's'){
        scanf(" %c", &resposta);
        if(resposta == 's'){
            cadastraSmartphone(i, phones);
            i++;
        }
    }

    Smartphone reqMin;
    scanf("%d\n%f\n%f\n%f", &reqMin.memoria, &reqMin.processador, &reqMin.camera, &reqMin.bateria);
    pesquisaSmartphones(i, phones, reqMin);


    // printf("%d %f %f %f", reqMin.memoria, reqMin.processador, reqMin.camera, reqMin.bateria);
    return 0;
}
