#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_PORTS 3
sem_t port_semaphore;
void* use_port(void* arg) {
    int port_id = *(int*)arg;
    sem_wait(&port_semaphore);
    printf("Port %d opened.\n", port_id);
    sleep(2);
    printf("Port %d closed.\n", port_id);
    sem_post(&port_semaphore);
    free(arg);
    return NULL;
}
int main() {
    pthread_t threads[6];
    sem_init(&port_semaphore, 0, MAX_PORTS);
    for (int i = 0; i < 6; i++) {
        int* port_id = (int*)malloc(sizeof(int));
        *port_id = i + 1;
        pthread_create(&threads[i], NULL, use_port, port_id);
    }
    for (int i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&port_semaphore);
    printf("All ports are closed. Simulation complete.\n");
    return 0;
}
