#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    char *text;
    struct node *prev;
    struct node *next;
} node_t;

node_t *head;

void push(node_t *node) {
    if (!head) {
        head = node;
    } else {
        node_t* tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
        node->prev = tmp;
    }
}


void printList() {
    if (head) {
        node_t* current = head;
        while (current != NULL) {
            printf("%s\n", current->text);
            current = current->next;
        }
    }
}

node_t* newNode(char* data) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->text = data;

    return newNode;
} 

int main() {
    node_t* n1 = newNode("a");
    push(n1);
    node_t* n2 = newNode("b");
    push(n2);
    node_t* n3 = newNode("c");
    push(n3);
    printList();

    return 0;
}
