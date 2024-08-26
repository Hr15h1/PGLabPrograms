#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;

}

struct Node* insertAtBeginning(struct Node* head, int data){
    struct Node* new_node = createNode(data);

    new_node -> next = head;
    head = new_node;
}

struct Node* reverseLinkedList(struct Node* head){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    printf("The linked list has been reversed\n");
    return prev;
}

void printLinkedList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void main(){
    int n, data;
    struct Node* head = NULL;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the data: ");
        scanf("%d", &data);
        head = insertAtBeginning(head, data);
    }
    printf("The linked list you have entered is: ");
    printLinkedList(head);
    head = reverseLinkedList(head);
    printLinkedList(head);

}