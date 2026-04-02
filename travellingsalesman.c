#include <stdio.h>
#include <limits.h>

#define MAX 16
#define INF INT_MAX

int n;
int dist[MAX][MAX];
int memo[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (memo[mask][pos] != -1)
        return memo[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }
    return memo[mask][pos] = ans;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            memo[i][j] = -1;

    int minCost = tsp(1, 0);

    printf("Minimum cost of TSP: %d\n", minCost);

    return 0;
}
