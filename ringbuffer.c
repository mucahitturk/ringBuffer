/*********************** Includes             *********************************/
#include "ringbuffer.h"
/*********************** Macros               *********************************/
/*********************** Defines              *********************************/

/*********************** Typedefs             *********************************/
/*********************** Variables            *********************************/
/*********************** Functions            *********************************/
void initialize(ringBuffer_t *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

ringBufferStatus_e enqueue(ringBuffer_t *rb, int data) {
    if (isFull(rb)) {
        return RINGBUFFER_ERROR_FULL_e; // Returns an error when the ring buffer is full.
    }

    rb->buffer[rb->tail] = data;
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count++;

    return RINGBUFFER_SUCCESS_e; // Data successfully enqueued.
}

ringBufferStatus_e dequeue(ringBuffer_t *rb, int *data) {
    if (isEmpty(rb)) {
        return RINGBUFFER_ERROR_EMPTY_e; // Returns an error when the ring buffer is empty.
    }

    *data = rb->buffer[rb->head];
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count--;

    return RINGBUFFER_SUCCESS_e; // Data successfully dequeued.
}

bool isFull(ringBuffer_t *rb) {
    return rb->count == BUFFER_SIZE;
}

bool isEmpty(ringBuffer_t *rb) {
    return rb->count == 0;
}
