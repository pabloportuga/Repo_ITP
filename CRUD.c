#include <stdio.h>
#include<string.h>

typedef struct Criar{
    char nome[50];
    int idade;
    char sexo;
} Criar;

void cadastra(int i, Criar pessoa[]){
    scanf(" %[^\n]s", pessoa[i].nome);
    scanf("%d\n%c\n", &pessoa[i].idade, &pessoa[i].sexo);
}
void del(Criar deletar[]){
    scanf(" %[^\n]s", deletar[0].nome);
    scanf("%d\n%c\n", &deletar[0].idade, &deletar[0].sexo);
}

int main(){
    Criar pessoa[50] = {0};
    Criar deletar[50] = {0};
    char ato;
    int i = 0;
    do{
        scanf("%c", &ato);
        if(ato == 'i'){
            cadastra(i, pessoa);
            i++;
        }
        if(ato == 'd'){
            del(deletar);
            for(int j= 0; j<i;j++){
                if(strcmp(deletar[0].nome,pessoa[j].nome)==0 && pessoa[j].idade==deletar[0].idade &&pessoa[j].sexo==deletar[0].sexo){
                    for(int k=0;k<i-j;k++){
                        strcpy(pessoa[j+k].nome,pessoa[j+1+k].nome);
                        pessoa[j+k].idade = pessoa[j+1+k].idade;
                        pessoa[j+k].sexo = pessoa[j+1+k].sexo;
                    }
                    i--;
                    break;
                }
            }
        }


    }while(ato != 'p');
    for(int j=0; j<i;j++){
        printf("%s,%d,%c\n", pessoa[j].nome, pessoa[j].idade, pessoa[j].sexo);
    }
    return 0;
}
