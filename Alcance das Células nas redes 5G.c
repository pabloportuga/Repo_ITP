#include <stdio.h>
int get_range(int n, int cells[n], int distance, int user, int left_index, int right_index){
    int i, count = 0;
    for(i=0;i<n;i++){
        if(cells[i]<=right_index && cells[i]>= left_index){
            printf("%d ", cells[i]);
            count =1;
        }
    }
    if(count == 0){
        printf("USUARIO DESCONECTADO");
    }
}

int main(){
    int n, distance, user;

    scanf("%d %d %d", &n, &distance, &user);
    int cells[n];

    for(int i=0;i<n;i++){
        scanf("%d", &cells[i]);
    }

    int left_index = user - distance;
    int right_index = user + distance;

    get_range(n, cells, distance, user, left_index, right_index);
    return 0;
}
