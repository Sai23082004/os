 #include <stdio.h>
 #include <stdlib.h>
 int main() {
    int f[50] = {0};  
    int st, len, j, c;
    do {
        printf("\nEnter the starting block & length of file: ");
        scanf("%d %d", &st, &len);
        if (st < 0 || st + len > 50) {
            printf("\nInvalid block range! Choose a valid range.\n");
            continue;
        }
        int allocated = 1;
        for (j = st; j < st + len; j++) {
            if (f[j] == 1) {
                printf("\nBlock %d is already allocated!", j);
                allocated = 0;
                break;
            }
        }
        if (allocated) {
            for (j = st; j < st + len; j++) {
                f[j] = 1;
                printf("\n%d -> Allocated", j);
            }
            printf("\nThe file is allocated to disk.");
        }
        printf("\nDo you want to enter more files? (1 - Yes, 0 - No): ");
        scanf("%d", &c);
    } while (c == 1);
    return 0;
}