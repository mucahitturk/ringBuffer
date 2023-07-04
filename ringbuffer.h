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
/* 
** @brief  : Initializes the ring buffer structure to its initial state.
** @param  : rb - Pointer to the ringBuffer_t structure.
** @return : none
*/
void initialize(ringBuffer_t *rb);

/* 
** @brief  : Enqueues data into the ring buffer and returns error status if 
             applicable.
** @param  : rb - Pointer to the ringBuffer_t structure.
**           data - Data to be enqueued.
** @return : ringBufferStatus_e - Error status indicating success or failure 
             of the operation.
*/
ringBufferStatus_e enqueue(ringBuffer_t *rb, uint32_t data);

/* 
** @brief  : Dequeues data from the ring buffer and returns error status if 
             applicable.
** @param  : rb - Pointer to the eingBuffer_t structure.
**           data - Pointer to the variable where dequeued data will be stored.
** @return : eingBufferStatus_e - Error status indicating success or failure
             of the operation.
*/
ringBufferStatus_e dequeue(ringBuffer_t *rb, uint32_t *data);

/* 
** @brief  : Checks if the ring buffer is full.
** @param  : rb - Pointer to the ringBuffer_t structure.
** @return : bool - True if the ring buffer is full, false otherwise.
*/
bool isFull(ringBuffer_t *rb);

/* 
** @brief  : Checks if the ring buffer is empty.
** @param  : rb - Pointer to the ringBuffer_t structure.
** @return : bool - True if the ring buffer is empty, false otherwise.
*/
bool isEmpty(ringBuffer_t *rb);

#endif
