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

struct Node* insertNode(struct Node* head, int data){
    struct Node* new_node = createNode(data);
    new_node -> next = head;
    head = new_node;
}

void searchElement(struct Node* head, int element){
    struct Node* temp = head;
    int flag = 0;
    while(temp != NULL){
        if(temp -> data == element){
            flag = 1;
            break;
        }
        temp = temp -> next;
    }
    if (flag == 1){
        printf("Element found in the linked list\n");
    } else {
        printf("Element not found in the linked list\n");
    }
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
    int n, data, element;
    struct Node* head = NULL;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the data: ");
        scanf("%d", &data);
        head = insertNode(head, data);
    }
    printf("The linked list you have entered is: ");
    printLinkedList(head);
    printf("\n");
    printf("Enter the element you want to search: ");
    scanf("%d", &element);
    searchElement(head, element);

}