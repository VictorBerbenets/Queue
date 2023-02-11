#ifndef Queue_Struct
#define Queue_Struct

#include <stdio.h>

typedef double Data;

typedef struct {

    size_t tail;
    size_t head;
    Data data;
    size_t data_size;
} Queue;


void Queue_Push(Queue* queue, Data value);

Data Queue_Pop(Queue* queue);

void Log_Queue(Queue* queue);


#endif