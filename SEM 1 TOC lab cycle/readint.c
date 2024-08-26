#include <stdio.h>
void main(){
    int element, a[100], i = 0;
    char input[100];
    printf("Enter some elements into the array: ");
    while(1){
        fgets(input, sizeof(input), stdin);
        if (input[0] == '\n'){
            break;
        }
        else{
            sscanf(input, "%d", &a[i]);
            i++;
        }
    }
    printf("The elements of the array are: ");
    for(int j = 0; j < i; j++){
        printf("%d ", a[j]);
    }
    printf("\n");
}