#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_CAPACITY 1024  // Define the capacity of the queue

// Structure for the circular queue
typedef struct CircularQueue {
    char *data;               // Pointer to hold dynamically allocated memory
    int head;                 // Index of the front element
    int tail;                 // Index of the next position to insert
    int size;                 // Current size of the queue
    int capacity;             // Maximum capacity of the queue
} CircularQueue;

// Initialize the circular queue
int init_queue(CircularQueue *queue, int capacity) {
    queue->data = (char *)malloc(capacity * sizeof(char));
    if (!queue->data) {
        printf("Memory allocation failed\n");
        return 0;  // Failure
    }
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return 1;  // Success
}

// Clean up the queue
void free_queue(CircularQueue *queue) {
    if (queue->data) {
        free(queue->data);
        queue->data = NULL;
    }
    queue->head = queue->tail = queue->size = 0;
}

// Function to add multiple bytes to the queue
int enqueue_bytes(CircularQueue *queue, const char *data, int size) {
    int i;
    if (queue->size + size > queue->capacity) {
        printf("Queue overflow: Not enough space to enqueue %d bytes\n", size);
        return 0;  // Failure
    }

    for (i = 0; i < size; i++) {
        queue->data[queue->tail] = data[i];
        queue->tail = (queue->tail + 1) % queue->capacity;
    }
    queue->size += size;
    printf("Enqueued %d bytes\n", size);
    return 1;  // Success
}

// Function to remove multiple bytes from the queue
int dequeue_bytes(CircularQueue *queue, char *buffer, int size) {
    int i, bytes_to_dequeue;
    if (queue->size == 0) {
        printf("Queue underflow: No data to dequeue\n");
        return 0;  // Failure
    }

    bytes_to_dequeue = (size < queue->size) ? size : queue->size;
    for (i = 0; i < bytes_to_dequeue; i++) {
        buffer[i] = queue->data[queue->head];
        queue->head = (queue->head + 1) % queue->capacity;
    }
    queue->size -= bytes_to_dequeue;
    printf("Dequeued %d bytes\n", bytes_to_dequeue);
    return bytes_to_dequeue;  // Success
}

// Function to display the queue content
void display_queue(const CircularQueue *queue) {
    int i, index;
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue content: ");
    index = queue->head;
    for (i = 0; i < queue->size; i++) {
        printf("%c", queue->data[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    CircularQueue queue;
    char buffer[20];
    int dequeued_size;

    // Initialize the queue with a capacity
    if (!init_queue(&queue, QUEUE_CAPACITY)) {
        return 1;  // Exit if initialization fails
    }

    // Test enqueue and dequeue
    enqueue_bytes(&queue, "Hello", 5);
    enqueue_bytes(&queue, "World", 5);
    enqueue_bytes(&queue, "CircularQueue", 13);

    display_queue(&queue);

    dequeued_size = dequeue_bytes(&queue, buffer, sizeof(buffer));
    buffer[dequeued_size] = '\0';  // Null-terminate for display
    printf("Dequeued Data: %s\n", buffer);

    display_queue(&queue);

    // Free the queue memory
    free_queue(&queue);

    return 0;
}

