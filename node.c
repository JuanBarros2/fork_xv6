#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    int priority;
    struct node* next;
} Node;

// Function to check is list is empty
int isEmpty(Node** head)
{
    return head == NULL || (*head) == NULL;
}

// Function to Create A New Node
Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
    if(!isEmpty(head)){
        Node* temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}

// Function to push according to priority
void push(Node** head, int d, int p){
    if((*head) == NULL){
        Node* temp = newNode(d, p);
        (*head) = temp;
    } else if ((*head)->priority > p ) {
        Node* temp = newNode(d, p);
        temp->next = (*head);
        (*head) = temp;
    } else {
        push(&((*head)->next), d+1, p);
    }
}
