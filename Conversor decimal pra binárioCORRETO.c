#include <stdio.h>
#include <math.h>
#include <limits.h>
int recursao(int n, int i,int binario[32]){
    binario[i]=n%2;
    n=n/2;
    i++;
    if(n!=0){
        return recursao(n, i, binario);
    }
    else{
        int j = i-1;
        for(j;j>=0;j--)
        printf("%d", binario[j]);
        return 0;
    }
}

int main(){
    int n;
    int i=0, binario[32];

    scanf("%d", &n);
    recursao(n, i, binario);
    return 0;
}
