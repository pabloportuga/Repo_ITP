#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[5]; //para não ter que digitar muito =)
	char *linhas[10]; //um vetor com 10 strings.
	for(int i=0; i<10; i++) //se tiver inicializado a gente pode confiar no valor
		linhas[i] = NULL;
	int l = 0; //índice da linha atual
	while(l<10){
		fgets(str,5,stdin);
		if(linhas[l] == NULL){ //primeia vez que usamos esse elemento
			linhas[l] = malloc(sizeof(char)*(strlen(str)+1));//para +1 caber o \0
			strcpy(linhas[l],""); //inicializa com uma string vazia
		}
		else //não é a primeira vez que usamos, então usamos realloc
			linhas[l] = realloc(linhas[l], sizeof(char)*(strlen(linhas[l])+strlen(str)+1)); //considera a string atual e a nova parte que será concatenada

		strcat(linhas[l],str); //adiciona a string atual à string que está guardada no vetor

		if(str[strlen(str)-1] == '\n') //caso tenha sido lido o fim da linha atual passa para a proxima posição do vetor
			l++;
	}

	for(int i=l-1; i>=0; i--) //imprime de tras pra frente
		printf("%s",linhas[i]);
	for(int i=0; i<l; i++) //libera a memória alocada
			free(linhas[i]);
	return 0;
}
