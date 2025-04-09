#include <stdio.h>
 #include <string.h>
 int main() {
    int alloc[10][10], max[10][10], avail[10], work[10], total[10];
    int need[10][10], n, m, i, j, k;
    int count = 0, c = 0;
    char finish[10];
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &n, &m);
    // Initialize finish array
    for (i = 0; i < n; i++) 
        finish[i] = 'n';
    // Input claim (max) matrix
    printf("Enter the claim (maximum) matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    // Input total available resources
    printf("Enter the total resource vector:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);
    // Calculate available resources
    for (i = 0; i < m; i++)
        avail[i] = total[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            avail[j] -= alloc[i][j];
    // Initialize work array with available resources
    for (i = 0; i < m; i++)
        work[i] = avail[i];
    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    // Banker's Algorithm
    int executed = 1; // To check if any process executed in an iteration
    while (count < n && executed) {
        executed = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 'n') {
                c = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] <= work[j])
                        c++;
                }
                if (c == m) { // All resources can be allocated
                    printf("\nProcess %d is executing.", i + 1);
                    // Release allocated resources
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    printf("\nAvailable resources after executing P%d:", i + 1);
                    for (k = 0; k < m; k++)
                        printf(" %d", work[k]);
                    finish[i] = 'y';
                    printf("\nProcess %d executed successfully.\n", i + 1);
                    count++;
                    executed = 1; // At least one process executed in this cycle
                }
            }
        }
    }
    if (count == n) {
        printf("\nSystem is in a safe state.\n");
        printf("The given state is a SAFE state.\n");
    } else {
        printf("\nSystem is in an UNSAFE state! Deadlock maay occur.\n");
    }
    return 0;
}