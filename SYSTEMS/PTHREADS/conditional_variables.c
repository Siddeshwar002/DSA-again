#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// ---------------------TOPICS-----------------------
//
// MUTEX
// CONDITIONAL VARIABLES
//
// ---------------------TOPICS-----------------------

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;

// Declare mutex and cond vars (uninitialized)
pthread_mutex_t mutex;
pthread_cond_t cond_producer;
pthread_cond_t cond_consumer;

void* producer(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        
        // Wait for the signal from the consumer
        while (count == BUFFER_SIZE) {
            printf("Producer waiting (buffer full)\n");
            pthread_cond_wait(&cond_producer, &mutex);
        }

        buffer[count++] = i;
        printf("Produced: %d (count=%d)\n", i, count);

        pthread_cond_signal(&cond_consumer);
        pthread_mutex_unlock(&mutex);
        usleep(100000);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        
        // Wait for the signal from the producer
        while (count == 0) {
            printf("Consumer waiting (buffer empty)\n");
            pthread_cond_wait(&cond_consumer, &mutex);
        }

        int item = buffer[--count];
        printf("Consumed: %d (count=%d)\n", item, count);

        pthread_cond_signal(&cond_producer);
        pthread_mutex_unlock(&mutex);
        usleep(200000);
    }
    return NULL;
}

int main() {
    // Initialize at runtime
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_producer, NULL);
    pthread_cond_init(&cond_consumer, NULL);

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Cleanup
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_producer);
    pthread_cond_destroy(&cond_consumer);

    return 0;
}