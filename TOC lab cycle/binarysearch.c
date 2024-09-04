#include <stdio.h>

int binarySearch(int arr[], int size, int value){
    int beg = 0, end = size - 1;
    int index;
    int mid;
    while (beg <= end){
        mid = (beg + end) / 2;
        if(arr[mid] == value){
            index = mid;
            break;
        } else if (arr[mid] > value){
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    if(beg > end){
        return -1;
    } else {
        return index;
    }
}


int arraySorter(int arr[], int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j + 1]){
                temp = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void main(){
    int size, value, index;
    printf("Enter the size of your array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the element: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    arraySorter(arr, size);
    printf("Sorting the array...\n");
    printf("The array you have entered after sorting is: \n");
        for(int i = 0; i < size; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");
    printf("Enter an element to search for: ");
    scanf("%d", &value);
    index = binarySearch(arr, size, value);
    if(index == -1){
        printf("The element you have entered cannot be found!");
    } else {
        printf("The element you have entered is found at %d.", index);
    }
}