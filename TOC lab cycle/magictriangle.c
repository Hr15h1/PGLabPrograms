#include<stdio.h>
// void main(){
//     int size;
//     printf("Enter the size of the triangle: ");
//     int s = size;
//     scanf("%d", &size);
//     for(int i = size; i > 0; i--){

//         for(int j = i + 1; j < size; j++){
//             printf("  %d  ", i);
//         }
//         printf("\n");
//     }
// }
void main(){
    int size;
    int k = 1;
    printf("Enter the size of the triangle: ");
    int s = size;
    scanf("%d", &size);
    for(int i = 0; i < size; i++){

        for(int j = 0; j < i + 1; j++){
            printf("   %d", k);
            k++;
        }
        printf("\n");
    }
}