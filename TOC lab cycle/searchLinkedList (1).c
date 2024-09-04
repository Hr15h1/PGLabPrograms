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


int searchList(struct Node* head, int val){
    int index = 1;
    int flag = 0;
    struct Node* temp = head;
    while(temp != NULL){
        
        if(temp -> data == val){
            flag = 1;
            break;
        }
        index++;
        temp = temp -> next;
    }
    if(flag == 1){
        return index;
    } else {
        return -1;
    }
}

void main(){
    int size, data, val, index = 0;
    struct Node* head = NULL;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    printf("Enter the elements: \n");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        head = insertAtBeginning(head, data);
    }
    printf("The list you have entered is: \n");
    printList(head);
    printf("Enter the element that you want to search: ");
    scanf("%d", &val);
    index = searchList(head, val);
    if(index != -1){
        printf("The element is found at %d", index);
        
    } else {
        printf("Couldn't find the element in the list");
    }
}