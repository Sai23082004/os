#include<stdio.h>
#define MAX 25
int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, lowest;
    static int bf[MAX], ff[MAX];  // To track which blocks are allocated
    // Input the number of blocks and files
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    // Input the sizes of the blocks
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }
    // Input the sizes of the files
    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }
    // Best Fit Memory Allocation Logic
    for (i = 1; i <= nf; i++) {  
        lowest = 10000;  
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {  
                temp = b[j] - f[i];  
                if (temp >= 0 && temp < lowest) {  
                    ff[i] = j;  
                    lowest = temp;  
                }
            }
        }
        frag[i] = lowest;  
        bf[ff[i]] = 1;  
    }
    // Output the results
    printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment\n");
    for (i = 1; i <= nf; i++) {
        if (ff[i] != 0) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        }
    }
}
