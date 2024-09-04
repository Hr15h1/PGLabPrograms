#include <stdio.h>
#define INF 999
void floydWarshall(int V, int dist[][V]){
    printf("Calculating shortest path between nodes..\n");
    for(int k = 0; k < V; k++){
        
        for(int j = 0; j < V; j++){

            for(int i = 0; i < V; i++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Calculation Complete!\n");
}

void printMatrix(int V, int dist[][V]){
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dist[i][j] >= INF){
                printf("INF ");
            } else {
                printf("%d   ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void main(){
    int size;
    printf("Enter the size of the adjaceny matrix: ");
    scanf("%d", &size);
    int arr[size][size];
    printf("Enter the adjaceny matrix: \n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The adjaceny matrix you have entered is: \n");
    printMatrix(size, arr);
    floydWarshall(size, arr);
    printf("The adjaceny matrix after calculation is: \n");
    printMatrix(size, arr);
}