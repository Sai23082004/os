 #include <stdio.h>
 #include <stdlib.h>
 int f[50] = {0};  // File allocation array, all blocks initially free
 int main() {
    int i, j, k, indexBlock, n, c, index[50];
    do {
        printf("\nEnter index block: ");
        scanf("%d", &indexBlock);
        if (indexBlock < 0 || indexBlock >= 50) {
            printf("\nInvalid index block! Choose a block between 0 and 49.\n");
            continue;
        }
        if (f[indexBlock] == 1) {
            printf("\nBlock %d is already allocated!\n", indexBlock);
            continue;
        }
        f[indexBlock] = 1;
        printf("Enter the number of file blocks: ");
        scanf("%d", &n);
        printf("Enter the file block numbers: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &index[i]);
            if (index[i] < 0 || index[i] >= 50) {
                printf("\nInvalid block number %d! Must be between 0 and 49.\n", index[i]);
                i--;  
            }
                continue;
            if (f[index[i]] == 1) {
                printf("\nBlock %d is already allocated! Try again.\n", index[i]);
                i--;  
            }
        }
        for (j = 0; j < n; j++)
            f[index[j]] = 1;
        printf("\nFile allocated successfully!\n");
        printf("Index Block %d -> Files: ", indexBlock);
        for (k = 0; k < n; k++)
            printf("%d ", index[k]);
        printf("\n");
        printf("Enter 1 to add more files or 0 to exit: ");
        scanf("%d", &c);
    } while (c == 1);
    return 0;
}