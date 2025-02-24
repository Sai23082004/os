#include <stdio.h>

#define MAX 100

// Function to check if a page is in the frame and return its index
int checkHit(int incomingPage, int queue[], int frequency[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        if (queue[i] == incomingPage) {
            frequency[i]++; // Increase frequency if page is found
            return i;
        }
    }
    return -1;
}

// Function to print the current state of the frame
void printFrame(int queue[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames = 3, queue[MAX], frequency[MAX], occupied = 0, pagefault = 0;

    // Initialize frequency array
    for (int i = 0; i < MAX; i++) {
        frequency[i] = 0;
    }

    printf("Page  | Frame Contents\n");
    printf("----------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d     | ", incomingStream[i]);

        int hitIndex = checkHit(incomingStream[i], queue, frequency, occupied);

        // If page hit, just print frame
        if (hitIndex != -1) {
            printFrame(queue, occupied);
        } else if (occupied < frames) { 
            // If empty frame available, insert new page
            queue[occupied] = incomingStream[i];
            frequency[occupied] = 1; // Set frequency to 1
            pagefault++;
            occupied++;
            printFrame(queue, occupied);
        } else { 
            // LFU Replacement
            int minFreq = frequency[0], index = 0;

            // Find the least frequently used page
            for (int j = 1; j < frames; j++) {
                if (frequency[j] < minFreq) {
                    minFreq = frequency[j];
                    index = j;
                }
            }

            // Replace with the new page
            queue[index] = incomingStream[i];
            frequency[index] = 1;
            pagefault++;
            printFrame(queue, occupied);
        }
    }

    printf("----------------------\n");
    printf("Total Page Faults: %d\n", pagefault);
    return 0;
}
