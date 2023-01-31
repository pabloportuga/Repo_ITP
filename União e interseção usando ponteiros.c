#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int n;
    int *vetor;
}conjunto;

conjunto uniao(conjunto A, conjunto B){
    conjunto uniaoAB;
    uniaoAB.n = A.n;

    uniaoAB.vetor = malloc(sizeof(int) * A.n);

    for(int i = 0; i<A.n;i++){
        uniaoAB.vetor[i] = A.vetor[i];
    }

    for(int i = 0;i<B.n;i++){
        int count = 0;
        for(int j = 0;j<uniaoAB.n;j++){
            if(B.vetor[i] == uniaoAB.vetor[j]){
                count++;
                break;
            }
        }
        if(count == 0){
            // aumenta em 1 o tamanho do vetor uniaoAB e coloca i em uniao;
            uniaoAB.vetor = realloc(uniaoAB.vetor, sizeof(int) * (uniaoAB.n+1));
            uniaoAB.vetor[uniaoAB.n] = B.vetor[i];
            uniaoAB.n++;
        }
    }
    return uniaoAB;
}

conjunto intersecao(conjunto A, conjunto B){
    conjunto intersecaoAB;
    intersecaoAB.n = 0;
    int menor;

    if(A.n > B.n){
        menor = B.n;
    }else{
        menor = A.n;
    }
    intersecaoAB.vetor = malloc(sizeof(int) * menor);
    for(int i = 0;i<B.n;i++){
        for(int j = 0;j<A.n;j++){
            if(A.vetor[j] == B.vetor[i]){
                intersecaoAB.vetor[intersecaoAB.n] = B.vetor[i];
                intersecaoAB.n++;
            }
        }
    }
    return intersecaoAB;
}

int main(){
    conjunto A, B, uniaoAB, intersecaoAB;
    int i;

    scanf("%d", &A.n);
    A.vetor = malloc(sizeof(int) * A.n);
    for(i=0;i<A.n;i++){
        scanf("%d", &A.vetor[i]);
    }


    scanf("%d", &B.n);
    B.vetor = malloc(sizeof(int) * B.n);
    for(i=0;i<B.n;i++){
        scanf("%d", &B.vetor[i]);
    }

    uniaoAB = uniao(A, B);
    printf("A união B == {");
    for(i=0;i<uniaoAB.n;i++){
        if(i==0){
            printf("%d", uniaoAB.vetor[i]);
        }
        else{
            printf(" %d", uniaoAB.vetor[i]);
        }
    }
    if(uniaoAB.n==0){
        printf("vazio");
    }
    printf("}\n");



    intersecaoAB = intersecao(A, B);
    printf("A interseção B == {");
    for(i=0;i<intersecaoAB.n;i++){
        if(i==0){
            printf("%d", intersecaoAB.vetor[i]);
        }
        else{
            printf("% d", intersecaoAB.vetor[i]);
        }

    }
    if(intersecaoAB.n == 0){
        printf("vazio");
    }
    printf("}");



    return 0;
}
