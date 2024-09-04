//Program that prints the fibonacci series upto a limit set by the user.
#include <stdio.h>
#include <conio.h>
void main(){
    int a = 0, b = 1;
    int c, lim;
    printf("Enter a limit: ");
    scanf("%d", &lim);
    printf("the fibonacci series upto the limit is: ");
    printf("%d ", a);
    printf("%d ", b);
    for(int i = 0; i < lim - 2; i++){
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    getch();
}