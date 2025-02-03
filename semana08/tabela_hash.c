// Exercício 1256 do beecrowd

#include <stdio.h>
#include <stdlib.h>

#define MAX 200

int func_hash(int valor, int m) {
    return valor % m;
}

void imprime_tabela(int tabela_hash[][MAX], int lista_tam[], int m) {
    for(int i = 0; i < m; i++) {
        printf("%d ->", i);
        for(int j = 0; j < lista_tam[i]; j++) {
            if(j < lista_tam[i]-1) {
                printf(" %d ->", tabela_hash[i][j]);
            }

            else {
                printf(" %d ->", tabela_hash[i][j]);
            }
        }
        printf(" \\\n");
    }
}

int main() {
    int n, m, c;  
    scanf("%d", &n);
    
    int indice;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &m, &c);

        int numeros[c];
        // Lendo os números do arquivo de entrada: 
        for(int i = 0; i < c; i++) {
            scanf("%d ", &numeros[i]);
        }
        
        int tabela_hash[m][MAX];
        int lista_tam[m];

        // Inicialmente, cada lista em cada posição da tabela possui tamanho 0:
        for(int i = 0; i < m; i++) {
            lista_tam[i] = 0;
        }

        // Adicionando os números na tabela_hash e incrementando o tamanho de cada lista:
        for(int i = 0; i < c; i++) {
            indice = func_hash(numeros[i], m);
            tabela_hash[indice][lista_tam[indice]] = numeros[i];
            lista_tam[indice]++;
        }

        imprime_tabela(tabela_hash, lista_tam, m);
        if(i < n-1) {
            printf("\n");
        }
    }
    
    return 0;
}