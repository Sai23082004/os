#include <stdio.h>
#include <stdlib.h>

struct rr {
    int pno, btime, sbtime, wtime, lst;
} p[10];
int main() {
    int pp = -1, ts, flag, count, ptm = 0, i, n, twt = 0, totttime = 0;
    printf("\nROUND ROBIN SCHEDULING\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time slice: ");
    scanf("%d", &ts);

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].wtime = p[i].lst = 0;
        p[i].pno = i + 1;
        p[i].sbtime = p[i].btime;
    }

    printf("\nScheduling:\n");
    do {
        flag = 0;
        for (i = 0; i < n; i++) {
            count = p[i].btime;
            if (count > 0) {
                flag = 1;
                count = (count >= ts) ? ts : count;
                printf("\nProcess %d from %d", p[i].pno, ptm);
                ptm += count;
                printf(" to %d", ptm);
                p[i].btime -= count;
                if (pp != i) {
                    pp = i;
                    p[i].wtime += ptm - p[i].lst - count;
                    p[i].lst = ptm;
                }
            }
        }
    } while (flag);

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        int tat = p[i].sbtime + p[i].wtime;
        twt += p[i].wtime;
        totttime += tat;
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].sbtime, p[i].wtime, tat);
    }

    printf("\nTotal waiting time: %d", twt);
    printf("\nAverage waiting time: %.2f", (float)twt / n);
    printf("\nTotal turnaround time: %d", totttime);
    printf("\nAverage turnaround time: %.2f\n", (float)totttime / n);

    return 0;
}
