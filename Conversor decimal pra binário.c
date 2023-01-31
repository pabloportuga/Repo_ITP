#include <stdio.h>
#include <math.h>
#include <limits.h>
int recursao(int n, int i, int resto, int binario){
    resto = n%2;
    binario += resto*pow(10,i);
    n=n/2;
    i++;
    if(n!=0){
        return recursao(n, i, resto, binario);
    }
    else{
        printf("%d", binario);
        return 0;
    }
}

int main(){
    int n;
    int i=0, resto,binario=0;

    scanf("%d", &n);
    recursao(n, i, resto,binario);
    return 0;
}
