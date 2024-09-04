//Program that generates the palindrome of a user input number.
#include<stdio.h>
void main(){
    int num, rem, sum = 0;
    int numcopy;
    printf("Enter a number to get the palindrome: ");
    scanf("%d", &num);
    numcopy = num;
    while(numcopy > 0){
        rem = numcopy % 10;
        sum = sum * 10 + rem;
        numcopy /= 10;
    }
    printf("The palindrome of the number you have entered is: %d", sum);
}