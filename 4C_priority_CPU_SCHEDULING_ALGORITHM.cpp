#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pno;
    int pri;
    int btime;
    int wtime;
} sp;

int main() {
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;

    printf("\nPRIORITY SCHEDULING.\n");
    printf("\nEnter the number of processes:\n");
    scanf("%d", &n);

    p = (sp *)malloc(n * sizeof(sp));

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the burst time and priority:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d%d", &p[i].btime, &p[i].pri);
        p[i].pno = i + 1;
        p[i].wtime = 0;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].pri > p[j].pri) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        p[i].wtime = tbm;
        totwtime += p[i].wtime;
        tbm += p[i].btime;

        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].btime, p[i].wtime, p[i].wtime + p[i].btime);
    }

    totttime = totwtime + tbm;
    printf("\nTotal waiting time: %d", totwtime);
    printf("\nAverage waiting time: %.2f", (float)totwtime / n);
    printf("\nTotal turnaround time: %d", tbm);
    printf("\nAverage turnaround time: %.2f\n", (float)tbm / n);

    free(p);

    return 0;
}
