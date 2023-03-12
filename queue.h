#ifndef Queue_Struct
#define Queue_Struct

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "validator.h"
#include <iostream>


typedef double elem_t;
const short Queue_Size     = 1024;
const short Tail_max_value = Queue_Size - 1;

class Queue { 
public:

    Queue (int queue_size) {
        capacity_ = queue_size;
        data_     = new elem_t[capacity_];
    }

    elem_t QueuePop(Queue* queue);
    void QueuePush(Queue* queue, elem_t value);
    void _QueueLog(Queue* queue, int line, const char* func_name);
    short GetTail();
    short GetHead();
    size_t GetSize();
    size_t GetCapacity();
    elem_t GetDataValue(int value_id);

    ~Queue () {
        delete [] this->data_;
    }
private:

    elem_t* data_    = nullptr;
    size_t capacity_ = 0;   
    size_t size_     = 0;
    short tail_      = 0;
    short head_      = 0;

    void SetTail(short tail);
    void SetHead(short head);
    void SetSize(int value);
    void Push(elem_t value);

};

enum Queue_Errors {
    
    INVALID_DATA_SIZE = 0xDEADBEEF1,
    INVALID_POP_VALUE = 0xDEADBEEF2,

} ;

#define QueueLog(queue) _QueueLog(queue, __LINE__, __PRETTY_FUNCTION__);

#endif