// Exercício 1062 do beecrowd

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
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


void push(pilha *p, int valor) {
    no *novo = (no*) malloc(sizeof(no));

    // Se a memória foi alocada corretamente, a operação push é realizada:
    if(novo) {
        p->tam += 1;
        novo->valor = valor;
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
        printf("%d\n", p.topo->valor);
        p.topo = p.topo->proximo;
    }
}


void deletarPilha(pilha *p) {
    while(p->topo) {
        pop(p);
    }
}

int main() {
    int n, x;
    pilha a, b, resultado;

    while(scanf("%d", &n) != EOF) {
        if(!n) {
            break;
        }

        while(scanf("%d", &x)) {
            if(!x) {
                printf("\n");
                break;
            }

            inicializaPilha(&a);
            inicializaPilha(&b);
            inicializaPilha(&resultado);

            push(&a, x);
            push(&b, 1);

            for(int i = 2; i <= n; i++) {
                scanf("%d", &x);
                push(&a, x);
                push(&b, i);
            }

            while(a.tam != 0 || b.tam != 0 || resultado.tam != 0) {
                if(a.tam != 0 && b.tam != 0 && a.topo->valor == b.topo->valor){
                    pop(&a);
                    pop(&b);
                
                }else if(resultado.tam != 0 && b.tam != 0 && resultado.topo->valor == b.topo->valor){
                    pop(&resultado);
                    pop(&b);
                
                }else if(a.tam != 0){
                    push(&resultado, a.topo->valor);
                    pop(&a);                
                }
                
                else{
                    break;
                }
            } 

            if(a.tam == 0 && resultado.tam == 0 && b.tam == 0){
                printf("Yes\n");
            }
            
            else{
                printf("No\n");
            }

            deletarPilha(&a);
            deletarPilha(&b);
            deletarPilha(&resultado);
        }
    }
 
    return 0;
}