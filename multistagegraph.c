#include <stdio.h>

#define MAX 50
#define INF 9999

int main() {
    int n, i, j;
    int cost[MAX][MAX], dist[MAX];

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

    dist[n - 1] = 0;

    for (i = n - 2; i >= 0; i--) {
        dist[i] = INF;
        for (j = i + 1; j < n; j++) {
            if (cost[i][j] + dist[j] < dist[i]) {
                dist[i] = cost[i][j] + dist[j];
            }
        }
    }

    printf("Minimum cost from vertex 0 to %d: %d", n - 1, dist[0]);

    return 0;
}
