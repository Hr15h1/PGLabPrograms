#include<stdio.h>
#define INF 999


void floydWarshall(int V, int dist[][V]){
    int i, j, k;
    printf("Calculating the distance between every pair of vertices... \n");
    for(k = 0; k < V; k++){
        for(i = 0; i < V; i++){
            for(j = 0; j < V; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Distance calculated successfully! \n");
}

void printSolution(int V ,int dist[][V]){
    printf("The following matrix shows the shortest distances between every pair of vertices: \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dist[i][j] >= INF){
                printf("INF ");
            }
            else{
                printf("%d   ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void main(){
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int dist[V][V];
    printf("Enter the adjacency matrix: \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            scanf("%d", &dist[i][j]);
        }
    }
    printf("The adjacency matrix you Have entered is: \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dist[i][j] == INF){
                printf("INF   ");
            }
            else{
                printf("%d     ", dist[i][j]);
            }
        }
        printf("\n");
    }
    floydWarshall(V, dist);
    printSolution(V, dist);
    
}