#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = NULL;
    if(rear == NULL){
        front = rear = new_node;
        rear -> next = front;
    } else {
        rear -> next = new_node;
        rear = new_node;
        rear -> next = front;
    }
}

void dequeue(){
    struct Node *temp;
    temp = front;
    if(front == NULL && rear == NULL){
        printf("Queue is empty!\n");
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
    struct Node *temp = front;
    printf("The elements of the queue are: ");
    if(front == NULL && rear == NULL){
        printf("Queue is empty!\n");
    } else {
        while(temp -> next != front){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("%d \n", temp -> data);
    }
}

void main(){
    int n, data;
    int value;
    printf("Enter the number of elements you want to enqueue: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the data: ");
        scanf("%d", &data);
        enqueue(data);
    }
    display();
    printf("Enter the number of elements you want to dequeue: ");
    scanf("%d", &value);
    for(int i = 0; i < value; i++){
        dequeue();
    }
    display();
}