// Exercício 1063 do beecrowd

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char letra;
    struct No *proximo;
}no;


typedef struct Pilha {
    int tam;
    no *topo;
}pilha;


void inicializaPilha(pilha *p) {
    p->tam = 0;
    p->topo = NULL;
}


void push(pilha *p, char letra) {
    no *novo = (no*) malloc(sizeof(no));

    // Se a memória foi alocada corretamente, a operação push é realizada:
    if(novo) {
        p->tam += 1;
        novo->letra = letra;
        novo->proximo = p->topo;
        p->topo = novo;
    }
}


void pop(pilha *p) {
    // Verificando se a pilha não está vazia:
    if(p->topo != NULL) {
        p->tam -= 1;
        no *remover = p->topo;
        p->topo = remover->proximo;
        free(remover);
    }
}


void imprimirPilha(pilha p) {
    while(p.topo) {
        printf("%d\n", p.topo->letra);
        p.topo = p.topo->proximo;
    }
}


void deletarPilha(pilha *p) {
    while(p->topo) {
        pop(p);
    }
}

int main() {
    int n;
    char x;
    pilha p;
    char a[30], b[30];

    while(scanf("%d", &n) && n) {
        inicializaPilha(&p);
        
        for(int i = 0; i < n; i++) {
            scanf(" %c", &a[i]);
        }

        for(int i = 0; i < n; i++) {
            scanf(" %c", &b[i]);
        }
        
        a[n] = '\0';
        b[n] = '\0';

        int i = 0, j = 0;
        while(1) {
            if(p.tam != 0 && j < n && p.topo->letra == b[j]){
                pop(&p);
                printf("R");
                j++;
            }
                
            else if(i < n){
                push(&p, a[i]);
                printf("I");
                i++;
            }

            else{
                break;
            }
        } 
    
        if(p.tam == 0) {
            printf("\n");
        }
            
        else {
            printf(" Impossible\n");
        }

        deletarPilha(&p);   
    }
 
    return 0;
}
