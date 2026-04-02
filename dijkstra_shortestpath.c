#include <stdio.h>

#define MAX 50
#define INF 9999

int main() {
    int n, i, j, start;
    int cost[MAX][MAX], distance[MAX], visited[MAX] = {0};
    int min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
    }

    visited[start] = 1;
    distance[start] = 0;

    for (i = 1; i < n - 1; i++) {
        min = INF;

        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                next = j;
            }
        }

        visited[next] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && min + cost[next][j] < distance[j]) {
                distance[j] = min + cost[next][j];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", start, i, distance[i]);
    }

    return 0;
}
