#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;  // Declare a semaphore

void* producer(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Producer: Producing item %d\n", i);
        
        // Signal (increment semaphore) ++ 
        sem_post(&sem); 

        // Simulate work
        sleep(1);  
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; i++) {
        // Wait (decrement semaphore) -- 
        sem_wait(&sem);  
        printf("Consumer: Consumed item %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphore with value 0 (no items initially)
    sem_init(&sem, 0, 0);

    // Create threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Cleanup
    sem_destroy(&sem);
    return 0;
}