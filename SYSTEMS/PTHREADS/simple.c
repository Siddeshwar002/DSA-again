#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function that returns a value
void* thread_function(void* arg) {
    // Allocate memory for return value
    int* value = malloc(sizeof(int)); 
    
    *value = 42; 
    printf("Thread: Returning %d\n", *value);
    
    // Return pointer to the value
    // NEVER return the address for the local varibles.
    // once the call is retuned the variables are destroyed.
    // use malloc(), create space in heap.
    // store the value at that address return the address of that varible
    return value; 
}

int main() {
    pthread_t thread_id;
    int* thread_return_value;

    // Create the thread
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to finish and get its return value
    // receive the return address from the thread in the pointer you created.
    if (pthread_join(thread_id, (void**)&thread_return_value) != 0) {
        perror("Failed to join thread");
        return 1;
    }

    printf("Main: Thread returned %d\n", *thread_return_value);

    // Clean up the allocated memory
    free(thread_return_value);

    return 0;
}