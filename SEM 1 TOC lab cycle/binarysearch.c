#include <stdio.h>

int binarySearch(int arr[], int size, int value){
    int beg = 0, end = size - 1;
    int index;
    while(beg <= end){
        int mid = (beg + end) / 2;
        if(arr[mid] == value){
            index = mid;
            break;
        } else if (arr[mid] < value){
            beg = mid + 1;
        } else if (arr[mid] > value){
            end = mid - 1;
        }
    }
    if (beg > end){
        return -1;
    } else {
        return index;
    }
}

int arraySorter(int arr[]){
    int temp;
    for(int i = 0; i < sizeof(arr); i++){
        for(int j = i + 1; j < sizeof(arr); j++){
            if(arr[i] > arr[j + 1]){
                temp = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

void main(){
    int n, value;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the value you want to search: ");
    scanf("%d", &value);
    int result = binarySearch(arr, n, value);
    if(result == -1){
        printf("The value is not present in the array\n");
    } else {
        printf("The value is present at index %d\n", result);
    }
}
 