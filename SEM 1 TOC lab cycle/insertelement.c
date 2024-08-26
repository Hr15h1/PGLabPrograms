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

void printLinkedList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void insertAtPosition(struct Node** head, int index, int value){
    struct Node* temp = *head;
    struct Node* new_node = createNode(value);
    int i = 0;
    if(index == 0){
        new_node -> next = *head;
        *head = new_node;
        return;
    }
    while(i < index - 1){
        temp = temp -> next;
        i++;
    }
    if(temp == NULL){
        return;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
}


void main(){
    int n, data;
    int index, value;
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
    printf("Enter the index at which you want to insert the element: ");
    scanf("%d", &index);
    printf("Enter the value you want to insert: ");
    scanf("%d", &value);
    insertAtPosition(&head, index, value);
    printf("The linked list after inserting the element is: ");
    printLinkedList(head);


}