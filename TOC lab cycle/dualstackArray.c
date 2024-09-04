#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top1 = -1, top2 = SIZE - 1;

void push(int select_stack, int item){
    if(top1 == top2 - 1){
        printf("Stack Overflow! The stack is full, cannot enter more elements.");
        return;
    }
    if(select_stack == 1){
        stack[++top1] = item;
    } else {
        stack[--top2] = item;
    }
}

int pop(int select_stack){
    if(select_stack == 1){
        if(top1 == -1){
            printf("Stack underflow! Stack 1 is empty. Cannot delete any elements.");
            return -1;
        }
        int val = stack[top1];
        top1--;
        return val;
    } else {
        if(top2 == SIZE){
            printf("Stack underflow! Stack 2 is empty. Cannot delete any elements.");
            return -1;
        }
        int val = stack[top2];
        top2++;
        return val;
    }
}

void display(int select_stack){
    if(select_stack == 1){
        if(top1 == -1){
            printf("Stack 1 is empty. No elements to display!");
            return;
        }
        for(int i = 0; i <= top1; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
        return;
    } else {
        if(top2 == SIZE){
            printf("Stack 2 is empty. No elements to display!");
            return;
        }
        for(int i = SIZE; i >= top2; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
        return;
    }
}

void main(){
    char ch = 'y';
    int choice, select_stack, item, val;
    printf("This is a C program which implements two stacks in a single array. The size of the array is 100.\n");
    while(ch == 'y'){
        printf("Enter 1 for PUSH, 2 for POP, 3 for DISPLAY, 4 to EXIT from program: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("To which stack do you want to push the element: ");
                scanf("%d", &select_stack);
                printf("Enter the element: ");
                scanf("%d", &item);
                push(select_stack, item);
                break;

            case 2:
                printf("From which stack do you want to pop and element: ");
                scanf("%d", &select_stack);
                val = pop(select_stack);
                if(val != -1){
                    printf("The element popped from the stack is: %d\n", val);
                }
                break;
            
            case 3:
                printf("Which stack do you want to display: ");
                scanf("%d", &select_stack);
                display(select_stack);
                break;

            case 4:
                printf("Exiting...");
                exit(0);
            
            default:
                printf("Invalid choice!");
                break;
        }
        printf("Do you want to continue?(y/n)");
        while((getchar()) != '\n');
        ch = getchar();
    }
}