/*********************** Includes             *********************************/
#include "stdio.h"
#include "ringbuffer.h"

int main(){
	
	ringBuffer_t rb;
    initialize(&rb);
	
	// adds data
    enqueue(&rb, 10);
    enqueue(&rb, 20);
    enqueue(&rb, 30);
    enqueue(&rb, 40);
    enqueue(&rb, 50);
	enqueue(&rb, 60);
	enqueue(&rb, 70);
	enqueue(&rb, 80);
	enqueue(&rb, 90);
	enqueue(&rb, 100);
	
	// test function of isFull
	printf("Is the buffer full? %s\n", isFull(&rb) ? "Yes" : "No");
	
	// removes data
    int data;
    dequeue(&rb, &data);
    printf("Dequeued data: %d\n", data);
	
	dequeue(&rb, &data);
    printf("Dequeued data: %d\n", data);
	
	dequeue(&rb, &data);
    printf("Dequeued data: %d\n", data);
	
	dequeue(&rb, &data);
    printf("Dequeued data: %d\n", data);

	dequeue(&rb, &data);
    printf("Dequeued data: %d\n", data);
	
    // test function of the isEmpty   
    printf("Is the buffer empty? %s\n", isEmpty(&rb) ? "Yes" : "No");


	return 0;
}