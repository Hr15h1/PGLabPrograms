#include<stdio.h>
void main(){
    int a[50], ele, index = 0;
    char input[100];
    printf("Enter some elements to insert into the array: \n");
    while(1){
        fgets(input, sizeof(input), stdin);
        if(input[0] == '\n'){
            break;
        } else {
            sscanf(input, "%d", &a[index]);
            index++;
        }
    }
    printf("The array you have entered is: ");
    for(int i = 0; i < index; i++){
        printf("%d ", a[i]);
    }
}