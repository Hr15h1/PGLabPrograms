//This is a program to implement two stacks in a single array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top1 = -1, top2 = SIZE;

void push(int select_stack, int item){
    if(top1 == top2 - 1){
        printf("Stack Overflow! Cannot insert more elements. \n");
        return;
    }
    if(select_stack == 1){
        top1++;
        stack[top1] = item;
    } else {
        top2--;
        stack[top2] = item;
    }
}

int pop(int select_stack){
    if(select_stack == 1){
        if(top1 == -1){
            printf("Stack Underflow! Cannot delete more elements. \n");
            return -1;
        }
        int val = stack[top1];
        top1--;
        return val;
    } else {
        if(top2 == SIZE){
            printf("Stack Underflow! Cannot delete more elements. \n");
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
            printf("Stack 1 is empty. \n");
            return;
        }
        printf("The elements of stack1 are: \n");
        for(int i = 0; i <= top1; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
        return;
    } else {
        if(top2 == SIZE){
            printf("Stack 2 is empty. \n");
            return;
        }
        printf("The elements of stack2 are: \n");
        for(int i = SIZE - 1; i >= top2; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
        return;
    }
}

void main(){
    char ch = 'y';
    int select_stack, item, choice, val;
    printf("This is a program which implements two stacks in a single array. The size of the array is %d\n", SIZE);;
    while(ch == 'y'){
        printf("Enter 1 to push, 2 to pop, 3 to display, 4 to exit: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("To which stack do you want to push the element? (1 or 2): ");
                scanf("%d", &select_stack);
                printf("Enter the element you want to push: ");
                scanf("%d", &item);
                push(select_stack, item);
                break;
            case 2:
                printf("From which stack do you want to pop the element? (1 or 2): ");
                scanf("%d", &select_stack);
                val = pop(select_stack);
                if(val != -1){
                    printf("The popped element is: %d \n", val);
                }
                break;
            case 3:
                printf("Which stack do you want to display? (1 or 2): ");
                scanf("%d", &select_stack);
                display(select_stack);
                break;
            case 4:
                printf("Exiting the program. \n");
                exit(0);
            default:
                printf("Invalid choice. \n");
                break;
        }
        printf("Do you want to Continue? (y/n): ");
        while((getchar()) != '\n');
        ch = getchar();
    }
}