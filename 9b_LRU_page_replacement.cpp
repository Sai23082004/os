#include <stdio.h>
#include <limits.h>

int checkHit(int incomingPage, int queue[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        if (incomingPage == queue[i])
            return 1; // Page hit
    }
    return 0; // Page miss
}

void printFrame(int queue[], int occupied) {
    for (int i = 0; i < occupied; i++)
        printf("%d\t\t", queue[i]);
    printf("\n");
}

int findLRU(int queue[], int occupied, int incomingStream[], int currentIndex) {
    int distance[occupied];
    for (int i = 0; i < occupied; i++) {
        distance[i] = INT_MAX; // Initialize distance to a high value
        for (int j = currentIndex - 1; j >= 0; j--) {
            if (queue[i] == incomingStream[j]) {
                distance[i] = currentIndex - j;
                break;
            }
        }
    }

    // Find the page with the maximum distance (least recently used)
    int maxIndex = 0;
    int maxDistance = distance[0];
    for (int i = 1; i < occupied; i++) {
        if (distance[i] > maxDistance) {
            maxDistance = distance[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main() {
    int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames = 3, queue[frames], occupied = 0, pageFaults = 0;

    printf("Page\tFrame1\t\tFrame2\t\tFrame3\n");

    for (int i = 0; i < n; i++) {
        printf("%d:\t", incomingStream[i]);

        // Check if the page is already in the frame
        if (checkHit(incomingStream[i], queue, occupied)) {
            printFrame(queue, occupied);
            continue;
        }

        // If there's space in the frames, add the page
        if (occupied < frames) {
            queue[occupied] = incomingStream[i];
            occupied++;
            pageFaults++;
        } else { // Use LRU replacement if frames are full
            int lruIndex = findLRU(queue, occupied, incomingStream, i);
            queue[lruIndex] = incomingStream[i];
            pageFaults++;
        }

        printFrame(queue, occupied);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
