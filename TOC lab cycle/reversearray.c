#include <stdio.h>
void main(){
    int size;
    printf("Enter the aize of your array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the elements of the array: \n");
    for(int i = 0; i < size; i++){
        scanf("%d", &a[i]);
    }
    printf("The array you have entered is: \n");
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("The reverse of the array you have entered is: \n");
    for(int i = size - 1; i >= 0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");


}