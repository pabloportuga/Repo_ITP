#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto{
    int n;
    int *numeros;
}conjunto;
int uniao(conjunto A, conjunto B){
    int *uniaoAB;
    return *uniaoAB;
}

int intersecao(conjunto A, conjunto B){
    int *intersecaoAB;
    return *intersecaoAB;
}

int main(){
    conjunto A;
    conjunto B;
    char lixo;

    scanf("%d", &A.n);
    A.numeros = (int*)malloc((A.n)*sizeof(int));
    for(int i=0;i<A.n;i++){
        scanf("%c%d", &lixo, A.numeros);
    }

    scanf("%d", &B.n);
    B.numeros = (int*)malloc((B.n)*sizeof(int));
    for(int i=0;i<B.n;i++){
        scanf("%c%d", &lixo, &B.numeros);
    }


    uniao(A, B);

    intersecao(A, B);

    return 0;
}

