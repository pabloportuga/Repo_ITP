#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char string[1][61];
    int tamanho, i;

    fgets(string[0], 61, stdin);
    tamanho = strlen(string[0]);
    string[0][tamanho-1] = '\0';

    for(i=0;string[0][i];i++){
        if(i==0){
            if(string[0][i]>= 'a' && string[0][i]<= 'z'){
                string[0][i]= string[0][i]-32;
            }
        }
        else if(string[0][i-1]==' '){
            if(string[0][i]>= 'a' && string[0][i]<= 'z'){
                string[0][i]= string[0][i]-32;
            }
        }
        else{
            if(string[0][i]>= 'A' && string[0][i]<= 'Z'){
                string[0][i]= string[0][i]+32;
            }
        }
    }
    printf("%s", string);

    return 0;
}
