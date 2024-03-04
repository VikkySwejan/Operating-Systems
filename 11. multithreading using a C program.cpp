#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *thread1_function(void *arg) {
    printf("Thread 1 is running\n");
    int *value = (int *)arg;
    printf("Thread 1 received argument: %d\n", *value);
    pthread_exit(NULL);
}
void *thread2_function(void *arg) {
    printf("Thread 2 is running\n");
    char *message = (char *)arg;
    printf("Thread 2 received argument: %s\n", message);
    pthread_exit(NULL);
}
int main() {
    pthread_t thread1, thread2;
    int thread1_arg = 123;
    char *thread2_arg = "Hello from Thread 2";
    if (pthread_create(&thread1, NULL, thread1_function, &thread1_arg) != 0) {
        perror("pthread_create");
        exit(1);
    }
    if (pthread_create(&thread2, NULL, thread2_function, thread2_arg) != 0) {
        perror("pthread_create");
        exit(1);
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Both threads have finished\n");
    return 0;
}