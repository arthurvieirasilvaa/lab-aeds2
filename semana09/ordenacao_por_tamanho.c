// Exercício 1244 do beecrowd

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparacao(char *palavra1, char *palavra2) {   
    if(strlen(palavra1) != strlen(palavra2)) {
        return strlen(palavra2) - strlen(palavra1);
    }

    return 0;
}

void bubble_sort(char *palavras[], int num_palavras) {
    char *aux;

    for(int i = 0; i < num_palavras - 1; i++) {
        for(int j = 0; j < num_palavras - i - 1; j++) {
            // Compara o tamanho de duas palavras e verifica qual é maior:
            if(comparacao(palavras[j], palavras[j+1]) > 0) {
                // Troca duas palvras de lugar:
                aux = palavras[j];
                palavras[j] = palavras[j+1];
                palavras[j+1] = aux;
            }
        }
    }
}


int main() {
    int n;
    char linha[1000];
    char *palavras[50];

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++) {
        fgets(linha, 1000, stdin);

        // A seguir, obtemos as palavras de cada linha da entrada:
        char* token = strtok(linha, " \n");
        int num_palavras = 0;
        while(token) {
            palavras[num_palavras] = token;
            num_palavras++;
            token = strtok(NULL, " \n");
        }

        // Ordena as palavras em relação aos seus tamanhos:
        bubble_sort(palavras, num_palavras);
        // Imprime as palavras de cada caso de teste:
        for(int j = 0; j < num_palavras; j++) {
            if(j == num_palavras - 1) {
                printf("%s", palavras[j]);
            }
            
            else {
                printf("%s ", palavras[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}