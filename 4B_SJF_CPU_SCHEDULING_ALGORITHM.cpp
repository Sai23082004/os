#include <stdio.h>

struct sjf {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

void sortByBurstTime(struct sjf p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burstTime > p[j + 1].burstTime) {
                struct sjf temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i, currentTime = 0;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct sjf p[n];

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", p[i].pid);
        scanf("%d", &p[i].arrivalTime);
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].burstTime);
    }

    sortByBurstTime(p, n);

    for (i = 0; i < n; i++) {
        if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }
        p[i].completionTime = currentTime + p[i].burstTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        currentTime = p[i].completionTime;

        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }

    printf("\n%-10s%-15s%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time", "Waiting Time", "Turnaround Time");

    for (i = 0; i < n; i++) {
        printf("%-10d%-15d%-15d%-15d%-15d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }

    printf("\n%-30s%d\n", "Total Waiting Time:", totalWaitingTime);
    printf("%-30s%.2f\n", "Average Waiting Time:", (float)totalWaitingTime / n);
    printf("%-30s%d\n", "Total Turnaround Time:", totalTurnaroundTime);
    printf("%-30s%.2f\n", "Average Turnaround Time:", (float)totalTurnaroundTime / n);

    return 0;
}
