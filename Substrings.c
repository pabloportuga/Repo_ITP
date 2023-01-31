#include <stdio.h>
#include <string.h>

int main(){
    char substring[40];
    char texto[40];
    int i, j, count, count1;

    fgets(substring, 40, stdin);
    int tamSub = strlen(substring);
    substring[tamSub-1] = '\0';
    substring[40] = tolower(substring);

    fgets(texto,40,stdin);
    int tamTex = strlen(texto);
    texto[tamTex-1] = '\0';
    texto[40] = tolower(texto);


    for(i=0;i<tamTex;){
        j=0;
        count=0;
        while(texto[i]== substring[j]){
            printf("achou um char igual\n ");
           count++;
           j++;
           i++;
        }

        if(count==tamSub){
            count1++;
            count=0;
        }
        else{
            i++;
        }
    }
    printf("%s occurs %d times in %s", substring, count1, texto);
    return 0;
}
