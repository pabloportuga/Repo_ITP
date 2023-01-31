#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 100
#define MAX_TEXTO 101

void carrega_base(int posicao, char base[][MAX_TEXTO]){
    int tamanho;
    fgets(base[posicao], MAX_TEXTO, stdin);
    tamanho = strlen(base[posicao]);
    base[posicao][tamanho-1] = '\0';
}

void imprime_sugestoes(char* str, int tamanho, char base[][MAX_TEXTO]){
    int tam_sugestao, sugestoes = 0;

    for(int i=0;i<tamanho; i++){
        int sugerir = 1;
        int tam_atual = strlen(base[i]);
        tam_sugestao = strlen(str) -1;
        if(tam_atual < tam_sugestao){
            continue;
        }
        for(int j=0; j<tam_sugestao;j++){
            if(str[j]!= base[i][j]){
                sugerir = 0;
                break;
            }
        }
        if(sugerir){
            printf("Voce quis dizer: %s?\n", base[i]);
            sugestoes++;
        }
    }
    if(sugestoes==0){
        printf("Sem recomendaçôes\n");
    }
}

int main(){
    int i;
    char consultas[TAM][MAX_TEXTO] = {0};
    char string[MAX_TEXTO];
    int anteriores, novas;

    scanf("%d\n", &anteriores);

    for(i=0;i<anteriores;i++){
        carrega_base(i, consultas);
    }
    scanf("%d\n", &novas);
    for(i=0; i<novas;i++){
        fgets(string,MAX_TEXTO,stdin);
        imprime_sugestoes(string, anteriores, consultas);
        printf("\n");
    }
    return 0;
}
