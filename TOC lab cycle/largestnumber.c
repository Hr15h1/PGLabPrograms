#include <stdio.h>
int findLarger(int r, int c, int a[r][c]){
    int max = a[0][0];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] > max){
                max = a[i][j];
            }
        }
    }
    return max;
}

void main(){
    int r, c, larger_number;
    printf("How many rows and columns does your matrix have? ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    printf("Enter the elements: \n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix you have entered is: \n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
    
    printf("The largest number in the given matrix is: %d", findLarger(r, c, a));
}