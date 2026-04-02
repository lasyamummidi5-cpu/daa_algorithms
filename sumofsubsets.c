#include <stdio.h>

int n, target;

void sumOfSubsets(int set[], int subset[], int i, int subsetSize, int currSum) {
    if (currSum == target) {
        printf("{ ");
        for (int j = 0; j < subsetSize; j++)
            printf("%d ", subset[j]);
        printf("}\n");
        return;
    }

    if (i >= n || currSum > target)
        return;

    subset[subsetSize] = set[i];
    sumOfSubsets(set, subset, i + 1, subsetSize + 1, currSum + set[i]);

    sumOfSubsets(set, subset, i + 1, subsetSize, currSum);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int set[n], subset[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d:\n", target);
    sumOfSubsets(set, subset, 0, 0, 0);

    return 0;
}
