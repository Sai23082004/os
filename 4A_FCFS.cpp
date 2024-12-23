#include <stdio.h>

struct fcfs {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};
int main() {
    int n, i;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct fcfs p[n];
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", p[i].pid);
        scanf("%d", &p[i].arrivalTime);
        printf("Enter burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].burstTime);
    }

    p[0].completionTime = p[0].arrivalTime + p[0].burstTime;
    p[0].waitingTime = 0;
    p[0].turnaroundTime = p[0].completionTime - p[0].arrivalTime;
    totalTurnaroundTime += p[0].turnaroundTime;

    for (i = 1; i < n; i++) {
        p[i].completionTime = p[i - 1].completionTime + p[i].burstTime;
        p[i].waitingTime = p[i].completionTime - p[i].arrivalTime - p[i].burstTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }

    printf("\n%-10s%-15s%-15s%-15s%-20s\n", "Process", "Arrival Time", "Burst Time", "Waiting Time", "Turnaround Time");

    for (i = 0; i < n; i++) {
        printf("%-10d%-15d%-15d%-15d%-20d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }

    printf("\n%-30s%d\n", "Total Waiting Time:", totalWaitingTime);
    printf("%-30s%.2f\n", "Average Waiting Time:", (float)totalWaitingTime / n);
    printf("%-30s%d\n", "Total Turnaround Time:", totalTurnaroundTime);
    printf("%-30s%.2f\n", "Average Turnaround Time:", (float)totalTurnaroundTime / n);

    return 0;
}
