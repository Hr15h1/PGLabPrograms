#include <stdio.h>
#include <math.h>
#include <string.h>

int bintodec(char bin[]){
    int length = strlen(bin);
    int decimal = 0;
    int base = 2;
    for(int i = 0; i < length; i++){
        if(bin[i] == '1'){
            decimal += pow(base, length - 2 - i);
        }
    }
    return decimal;

}

void main(){
    char bin[100];
    printf("Enter a binary number: ");
    fgets(bin, 100, stdin);
    printf("The binary number you have entered is: %s\n", bin);
    printf("The decimal of the number is: %d", bintodec(bin));
}