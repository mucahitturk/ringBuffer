#ifndef RING_BUFFER_H
#define RING_BUFFER_H

/*********************** Includes             *********************************/
#include <stdbool.h>
#include <stdint.h>
/*********************** Macros               *********************************/

/*********************** Defines              *********************************/
#define BUFFER_SIZE 10
/*********************** Typedefs             *********************************/
typedef struct {
    uint32_t buffer[BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t count;
} ringBuffer_t;

typedef enum {
    RINGBUFFER_SUCCESS_e,
    RINGBUFFER_ERROR_FULL_e,
    RINGBUFFER_ERROR_EMPTY_e
} ringBufferStatus_e;
/*********************** Variables            *********************************/

/*********************** Functions            *********************************/
// Initializes the ring buffer structure to its initial state.
void initialize(ringBuffer_t *rb);

// Enqueues data into the ring buffer and returns error status if applicable.
ringBufferStatus_e enqueue(ringBuffer_t *rb, uint32_t data);

// Dequeues data from the ring buffer and returns error status if applicable.
ringBufferStatus_e dequeue(ringBuffer_t *rb, uint32_t *data);

// Checks if the ring buffer is full.
bool isFull(ringBuffer_t *rb);

// Checks if the ring buffer is empty.
bool isEmpty(ringBuffer_t *rb);

#endif
