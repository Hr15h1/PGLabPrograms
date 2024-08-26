#include <stdio.h>
#include <string.h>
#include <math.h>

int binarytodec(char bin[]){
    int decimal = 0;
    int len = strlen(bin);
    int base = 2;
    for(int i = 0; i < len; i++){
        if(bin[i] == '1'){
            decimal += pow(base, len - 2 - i);
        }
    }
    return decimal;
}


void main(){
    char bin[100];
    printf("Enter a binary number: ");
    fgets(bin, 100, stdin);
    printf("the decimal of the number is: %d", binarytodec(bin));
} 