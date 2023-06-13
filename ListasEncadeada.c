#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* fruit;
    struct Node* next;
} Node;

Node* createNode(char* fruit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->fruit = fruit;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, char* fruit) {
    Node* newNode = createNode(fruit);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    
    if (temp == NULL) {
        printf("The list of fruits is empty.\n");
    } else {
        printf("List of fruits:\n");
        while (temp != NULL) {
            printf("%s\n", temp->fruit);
            temp = temp->next;
        }
    }
}

int main() {
    Node* fruitList = NULL;
    
    insertNode(&fruitList, "Apple");
    insertNode(&fruitList, "Banana");
    insertNode(&fruitList, "Orange");
    
    displayList(fruitList);
    
    return 0;
}
