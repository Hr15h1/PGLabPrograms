//Program that checks if a user input number is an armstrong or not.

#include<stdio.h>
#include<math.h>
void main(){
    int num, rem, sum = 0;
    int cube = 0;
    int numcopy;
    printf("Enter a number: ");
    scanf("%d", &num);
    numcopy = num;
    while(numcopy > 0){
        rem = numcopy % 10;
        sum = sum + rem * rem * rem;
        numcopy /= 10;
    }
    if(sum == num){
        printf("The number you have entered is an armstrong number.");
    } else {
        printf("The number you have entered is not an armstrong number.");
    }

}