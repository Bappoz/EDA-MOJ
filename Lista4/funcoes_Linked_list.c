/*
 * funcoes_Linked_list.c
 * Implementação de funções básicas para lista ligada simples (singly linked list)
 * Cada função possui um comentário descrevendo o comportamento.
 * Inclui um main() de teste que demonstra uso das funções.
 */

#include <stdio.h>
#include <stdlib.h>

/* Definição do nó (celula) */
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


/* aloca_no: aloca uma nova célula com o dado informado
 * Retorna ponteiro para a célula (ou NULL em caso de falha).
 */
static celula *aloca_no(int dado){
    celula *novo = malloc(sizeof(celula));
    if(!novo) return NULL;
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

/* 
libera_lista: libera todos os nós da lista iniciando em le
 */
void libera_lista(celula *le){
    celula *tmp;
    while(le){
        tmp = le;
        le = le->prox;
        free(tmp);
    }
}

/* =====================
 * Inserção
 * ===================== */

/* insere_inicio: insere um novo nó no início da lista
 * Parâmetros: le (ponta da lista, pode ser NULL), dado
 * Retorna: novo início da lista
 */
celula *insere_inicio(celula *le, int dado){
    celula *novo = aloca_no(dado);
    if(!novo) return NULL;
    novo->prox = le;
    return novo;
}

/* insere_fim: insere um novo nó no final da lista
 * Retorna o início da lista (poderá ser o novo nó caso lista vazia)
 */
celula *insere_fim(celula *le, int dado){
    celula *novo = aloca_no(dado);
    if(!novo) return NULL;
    if(!le) return novo;
    celula *p = le;
    while(p->prox) p = p->prox;
    p->prox = novo;
    return le;
}

/* insere_posicao: insere em posição pos (0-based). Se pos<=0 insere no início.
 * Se pos maior que tamanho, insere no fim.
 * Retorna o início atualizado da lista.
 */
celula *insere_posicao(celula *le, int dado, int pos){
    if(pos <= 0) return insere_inicio(le, dado);
    if(!le) return insere_inicio(le, dado);
    celula *p = le;
    for(int i = 0; i < pos - 1 && p->prox; i++) p = p->prox;
    celula *novo = aloca_no(dado);
    if(!novo) return NULL;
    novo->prox = p->prox;
    p->prox = novo;
    return le;
}

/* =====================
 * Remoção
 * ===================== */

/* remove_inicio: remove o primeiro nó e retorna o novo início
 * Se lista vazia retorna NULL
 */
celula *remove_inicio(celula *le){
    if(!le) return NULL;
    celula *rem = le;
    le = le->prox;
    free(rem);
    return le;
}

/* remove_valor: remove a primeira ocorrência de 'valor'
 * Retorna início atualizado
 */
celula *remove_valor(celula *le, int valor){
    if(!le) return NULL;
    if(le->dado == valor){
        celula *tmp = le->prox;
        free(le);
        return tmp;
    }
    celula *p = le;
    while(p->prox && p->prox->dado != valor) p = p->prox;
    if(p->prox){
        celula *rem = p->prox;
        p->prox = rem->prox;
        free(rem);
    }
    return le;
}

/* =====================
 * Busca
 * ===================== */

/* busca: retorna ponteiro para primeiro nó contendo x, ou NULL se não achar */
celula *busca(celula *le, int x){
    celula *p = le;
    while(p){
        if(p->dado == x) return p;
        p = p->prox;
    }
    return NULL;
}

/* busca_pos: retorna ponteiro para nó na posição pos (0-based) ou NULL */
celula *busca_pos(celula *le, int pos){
    celula *p = le;
    int i = 0;
    while(p && i < pos){ p = p->prox; i++; }
    return p;
}

/* =====================
 * Impressão
 * ===================== */

/* imprime: imprime lista iterativamente no formato 'v1 -> v2 -> ... -> NULL' */
void imprime(celula *le){
    celula *p = le;
    while(p){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n");
}

/* imprime_rec: impressão recursiva (chamada pública) */
static void imprime_rec_aux(celula *no){
    if(no){
        printf("%d -> ", no->dado);
        imprime_rec_aux(no->prox);
    } else {
        printf("NULL\n");
    }
}

void imprime_rec(celula *le){
    imprime_rec_aux(le);
}

/* =====================
 * Função main para testes
 * ===================== */
int main(void){
    celula *le = NULL;
    printf("Criando lista e testando funcoes...\n");

    /* Inserções */
    le = insere_inicio(le, 5);   // 5
    le = insere_inicio(le, 4);   // 4 -> 5
    le = insere_fim(le, 10);     // 4 -> 5 -> 10
    le = insere_posicao(le, 7, 2); // insere 7 na pos 2: 4->5->7->10
    printf("Lista apos insercoes (iterativa):\n");
    imprime(le);

    printf("Lista (recursiva):\n");
    imprime_rec(le);

    /* Busca */
    celula *en = busca(le, 7);
    printf("Busca valor 7: %s\n", en ? "ENCONTRADO" : "NAO encontrado");

    celula *p2 = busca_pos(le, 2);
    if(p2) printf("Elemento na pos 2: %d\n", p2->dado);

    /* Remoções */
    le = remove_valor(le, 5); // remove 5
    printf("Lista apos remover 5:\n");
    imprime(le);

    le = remove_inicio(le); // remove inicio
    printf("Lista apos remover inicio:\n");
    imprime(le);

    /* Limpeza */
    libera_lista(le);
    printf("Lista liberada.\n");
    return 0;
}
