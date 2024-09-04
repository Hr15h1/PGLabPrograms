#include <stdio.h>
#include <stdlib.h>

struct Node{
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
    return head;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}


void insertAtPosition(struct Node** head, int value, int index){
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
    new_node -> next = temp -> next;
    temp -> next = new_node;
}

void main(){
    int index, data, value, size;
    struct Node* head = NULL;

    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    printf("Enter the elements of the list: \n");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        head = insertAtBeginning(head, data);
    }
    printf("The list you have entered is: \n");
    printList(head);
    printf("Enter the value to be added to the list: ");
    scanf("%d", &value);
    printf("Enter the position where you want the element to be inserted: ");
    scanf("%d", &index);
    if(index > size){
        printf("Cannot insert element at this index!");
        exit(0);
    }
    insertAtPosition(&head, value, index);
    printf("The new list is: \n");
    printList(head);
}

