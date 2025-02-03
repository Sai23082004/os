#include <stdio.h>
#define MAX 25
int main() {
    int frag[MAX], block[MAX], file[MAX], i, j, numBlocks, numFiles, temp, highest = 0;
    int blockFlag[MAX] = {0}, fileAllocation[MAX] = {0};
    printf("\n\tMemory Management Scheme - Worst Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &numBlocks);
    printf("Enter the size of the blocks:\n");
    for (i = 0; i < numBlocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);
    printf("Enter the size of the files:\n");
    for (i = 0; i < numFiles; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &file[i]);
    }
    // Worst fit allocation logic
    for (i = 0; i < numFiles; i++) {
        for (j = 0; j < numBlocks; j++) {
            if (blockFlag[j] == 0) { // If block[j] is not allocated
                temp = block[j] - file[i];
                if (temp >= 0 && temp > highest) {
                    fileAllocation[i] = j;
                    highest = temp;
                }
            }
        }
        if (fileAllocation[i] != 0 || (fileAllocation[i] == 0 && highest >= 0)) {
            frag[i] = highest;
            blockFlag[fileAllocation[i]] = 1;
        } else {
            frag[i] = -1; 
        }
        highest = 0;
    }
    // Display the allocation details
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (i = 0; i < numFiles; i++) {
        if (frag[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                   i + 1, file[i], fileAllocation[i] + 1, block[fileAllocation[i]], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, file[i]);
        }
    }
    return 0;
}
