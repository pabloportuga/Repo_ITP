#include <stdio.h>

typedef struct party{
    int identificador;
    char nome[10];
    int quantidade;
}party;

int main(){
    int i, j, count, num_parties, num_votes, vice, vencedor,valido=0;
    char lixo;

    scanf("%d", &num_parties);
    party parties[num_parties];

    for(i=0;i<num_parties;i++){
        scanf("%d%c", &parties[i].identificador, &lixo);
        scanf("%[^\n]s", parties[i].nome);
        parties[i].quantidade = 0;
    }

    scanf("%d", &num_votes);
    int votes[num_votes];

    for(i=0;i<num_votes;i++){
        int contador = 0;
        scanf("%d%c", &votes[i], &lixo);
        for(j=0;j<num_parties;j++){
            if(votes[i]==parties[j].identificador){
                contador++;
            }
        }
        if(contador){
            parties[votes[i]].quantidade++;
            valido++;
        }

    }
    for(i=0;i<num_parties;i++){
        count = 0;
        for(j=0;j<num_parties;j++){
            if(parties[i].quantidade>parties[j].quantidade){
                count++;
            }
        }
        if(count == num_parties-1){
            vencedor = i;
        }
        if(count == num_parties-2){
            vice = i;
        }
    }
    printf("VENCEDOR: %s(%d votos = %.2f%%)\n", parties[vencedor].nome, parties[vencedor].quantidade, parties[vencedor].quantidade*100/(float)valido);
    printf("Vice: %s(%d votos = %.2f%%)", parties[vice].nome, parties[vice].quantidade, parties[vice].quantidade*100/(float)valido);
    return 0;
}
