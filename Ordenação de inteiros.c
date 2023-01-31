#include <stdio.h>

int main(){
    int n, i = 0;
    int *vetor;
    char lixo;
    vetor = malloc(sizeof(int) * 100);
    while(scanf("%d%c", &n, &lixo)!= EOF){
        vetor[i] = n;
        i++;
    }
    for(int j=0;j<i;j++){
        printf("%d", vetor[j]);
    }
    free(vetor);
    return 0;
}
