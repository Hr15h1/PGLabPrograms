#include <stdio.h>
int largernum(int r, int c, int a[r][c]){
    int max = a[0][0];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (a[i][j] > max){
                 max = a[i][j];
            }
        }
    }
    return max;
}

void main(){
    int r, c;
    printf("Enter the number of rows and columns:  ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("The elements of the array are: \n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("The largest number in the array is: %d", largernum(r, c, a));
}