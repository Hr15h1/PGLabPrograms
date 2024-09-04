#include <stdio.h>
#include <stdlib.h>\

struct Node{
    int data; 
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = NULL;
    if(rear == NULL){
        front = rear = new_node;
        rear -> next = new_node;
    } else {
        rear -> next = new_node;
        rear = new_node;
        rear -> next = front;
    }
}

void dequeue(){
    struct Node* temp;
    temp = front;
    if(front == NULL && rear == NULL){
        printf("The queue is empty.\n");
    } else if(front == rear){
        front = rear = NULL;
        free(temp);
    } else {
        front = front -> next;
        rear -> next = front;
        free(temp);
    }
}

void display(){
    struct Node* temp = front;
    if(front == NULL && rear == NULL){
        printf("The queue is empty.\n");
    } else {
        while(temp -> next != front){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("%d ", temp -> data);
        printf("\n");
    }
}

void main(){
    int size, data, n;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    printf("Enter the elements: \n");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        enqueue(data);
    }
    printf("The list is: ");
    display();
    printf("Enter the number of elements to be removed: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        dequeue();
    }
    printf("The list after deleting the elements: \n");
    display();
}