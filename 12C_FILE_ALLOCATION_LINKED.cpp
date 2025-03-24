 #include <stdio.h>
 #include <stdlib.h>
 int main() {
    int f[50] = {0};  // File allocation array, all blocks initially free
    int p, i, j, a, st, len, c;
    // Getting the pre-allocated blocks
    printf("Enter the number of blocks that are already allocated: ");
    scanf("%d", &p);
    printf("Enter the block numbers that are already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a < 0 || a >= 50) {
            printf("Invalid block number %d! Must be between 0 and 49.\n", a);
            i--;  // Retry input
            continue;
        }
        f[a] = 1;
    }
    do {
        // Getting new file allocation details
        printf("\nEnter the starting index block and length: ");
        scanf("%d %d", &st, &len);
        if (st < 0 || st >= 50 || len <= 0 || (st + len) > 50) {
            printf("Invalid input! Ensure blocks are within range 0-49.\n");
            continue;
        }
        int allocated = 1;
        for (j = st; j < (st + len); j++) {
            if (f[j] == 1) {
                printf("\nBlock %d is already allocated!", j);
                allocated = 0;
            }
        }
        if (allocated) {
            for (j = st; j < (st + len); j++) {
                f[j] = 1;
                printf("\n%d -> Allocated", j);
            }
            printf("\nFile successfully allocated!\n");
        } else {
            printf("\nFile allocation failed! Some blocks are already in use.\n");
        }
        
        printf("\nDo you want to enter another file? (1 - Yes, 0 - No): ");
        scanf("%d", &c);
    } while (c == 1);
    return 0;
 }