#ifndef Queue_Struct
#define Queue_Struct

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "validator.h"

typedef double Data;

const short Queue_size     = 1024;
const short Tail_max_value = Queue_size - 1;

typedef struct {

    short tail;
    short head;
    Data data[Queue_size];
    size_t data_size;
} Queue;

enum Queue_Errors {
    
    INVALID_DATA_SIZE = 0xDEADBEEF1,
    INVALID_POP_VALUE = 0xDEADBEEF2,

} ;

Queue Queue_Init();

void Queue_Push(Queue* queue, Data value);

Data Queue_Pop(Queue* queue);

void _Queue_Log(Queue* queue, int line, const char* func_name);

#define Queue_Log(queue) _Queue_Log(queue, __LINE__, __PRETTY_FUNCTION__);

#endif