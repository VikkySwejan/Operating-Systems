#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    int item = rand() % 100; 
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    
    printf("Produced item: %d\n", item);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    return NULL;
}
