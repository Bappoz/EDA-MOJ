#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct Pilha {
    Node *topNode;
} Pilha;

// Cria uma nova pilha vazia, alocando memória para a struct Pilha e inicializando o topo como NULL.
Pilha* criarStack() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) return NULL;

    p->topNode = NULL;
    return p;
}

// Insere um novo elemento no topo da pilha, criando um novo nó e ajustando os ponteiros.
void push(Pilha* p, char *newData) {
    if(p == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    newNode->data = (char*)malloc(strlen(newData) + 1);
    strcpy(newNode->data, newData);

    newNode->next = p->topNode;
    p->topNode = newNode;
    // topNode -> newNode(Ex: 10) -> NULL
    // topNode -> newNode(Ex: 20) -> ExNewNode(Ex: 10) -> NULL
}

// Verifica se a pilha está vazia, retornando true se o topo for NULL.
bool is_empty(Pilha* p) {
    if(p == NULL) return true;
    return (p->topNode == NULL);
}

char* pop(Pilha* p) {
    if (is_empty(p)) return NULL;

    Node* tmp = p->topNode;
    char* texto = tmp->data;

    p->topNode = tmp->next;
    free(tmp);

    return texto;
}

void destruiPilha(Pilha *p) {
    if(p == NULL) return;

    while (!is_empty(p)) {
        char *texto = pop(p);
        if(texto != NULL) free(texto);   
    }

    free(p);
}


int main(){

    Pilha* p = criarStack();

    FILE *f = stdin;
    if(!f) return 1;
    char buf[110];

    while(fgets(buf, sizeof(buf), stdin)){
        size_t len = strlen(buf);
        while(len > 0 && (buf[len-1] == '\n' || buf[len-1] == '\r' || buf[len-1] == ' ')) {
            buf[len-1] = '\0';
            len--;
        }
        
        if(strcmp(buf, "desfazer") == 0){
            char *texto = pop(p);

            if(texto == NULL) printf("NULL\n");
            else{
                printf("%s\n", texto);
                free(texto);
            }
        }
        else if(strncmp(buf, "inserir ", 8) == 0){
            char *texto = buf + 8;
            push(p, texto);
        }
    }
        
     
    destruiPilha(p);
    return 0;
}