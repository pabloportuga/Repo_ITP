#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    const char S[]= {'0','1','2','3','4','5','6','7','8','9', 'A','B','C','D','E','F','G','H','I','J', 'K','L','M','N','O','P','Q','R','S','T', 'U','V','W','X','Y','Z','.',',','?',' '}; //40 btw
    int k, i, num[4], j=0, count1, m, n;
    char p[200];
    scanf("%d", &k); // 1357
    if(k>9999){
        printf("Chave invalida!");
        exit(0);
    }

    for(i=3;i>=0;i--){
        num[i] = k%10;
        k = k/10;
    }
    int lixo;
    scanf("\n", &lixo);
    fgets(p, 200, stdin);
    int tam = strlen(p);
    p[tam-1] = '\0';
    for(m=0;m<tam;m++){
        count1=0;
        for(n=0;n<40;n++){
            if(p[m]==S[n]){
                count1++;
            }
        }
        if(count1==0){
            printf("Caractere invalido na entrada!");
            exit(0);
        }
    }

    char c[tam];
    c[tam-1] = '0';
    int count, temp;

    for(i=0;i<tam-1;i++){
        int l=0;
        count = 0;
        while(count!=1){
            if( p[i] == S[l]){
                count=1;
            }
            else{
                l++;
            }
        }
        temp = l+num[j];
        if(temp > 39){
            temp = l + num[j] - 40;
        }
        c[i] = S[temp];
        j++;
        if(j==4){
            j=0;
        }
    }
    for(i=0;i<tam-1;i++){
        printf("%c", c[i]);
    }
    return 0;
}
