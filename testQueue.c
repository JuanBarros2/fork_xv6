#include <stdio.h>
#include "node.c"

typedef struct tabletype{
    int lock;
    Node* pq;
} tabletype;

tabletype *table = NULL;

void insertProcess() {
    int priority = 0;
    printf("Escolha a prioridade do processo:\n");
    scanf("%d", &priority);
    push(&(table->pq), 0, priority);
    printf("Foi adicionado um processo com prioridade %d\n", priority);
}

void printQueue(){
    for(Node* auxiliar = table->pq; auxiliar != NULL; auxiliar = auxiliar->next){
        printf("Prioridade > %d\n", auxiliar->priority);
    }
}

void removeProcess() {
    pop(&(table->pq));
}

int main() {
    int op = 0;
    table = (tabletype*) malloc(sizeof(tabletype));
    while(1){
        printf("===============================\n");
        printf("Escolha uma opcao:\n");
        printf("1- (Des)Locar tabela:\n");
        printf("2- Criar processo\n");
        printf("3- Rodar processo\n");
        printf("4- Mostrar fila\n");
        scanf("%d", &op);
        printf("...............................\n");
        switch (op){
            case 1:
                table->lock = (table->lock != 1 ? 1: 0);
                printf("A tabela está %s\n",table->lock ? "bloqueada" : "desbloqueada");
                break;
            case 2:
                insertProcess();
                break;
            case 3:
                removeProcess();
                break;
            case 4:
                printQueue();
                break;
            default:
                break;
            }
    }
}
