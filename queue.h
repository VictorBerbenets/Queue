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
    void SetHead(short head) {
        this->head_ = head;
    }
    short GetTail() {
        return tail_;
    }
    short GetHead() {
        return head_;
    }
    size_t GetSize() {
        return size_;
    }
    size_t GetCapacity() {
        return capacity_;
    }
    void SetSize(int value) {
        this->size_ = value;
    }
    void Push(elem_t value) {
        this->data_[this->tail_] = value;
    }
    elem_t GetDataValue(int value_id) {
        return this->data_[value_id];
    } 
    void SetTail(short tail) {
        this->tail_ = tail;
    }
    ~Queue () {
        delete [] this->data_;
    }

private:

    elem_t* data_    = nullptr;
    size_t capacity_ = 0;   
    size_t size_     = 0;
    short tail_      = 0;
    short head_      = 0;

    // void SetTail(short tail);
};
enum Queue_Errors {
    
    INVALID_DATA_SIZE = 0xDEADBEEF1,
    INVALID_POP_VALUE = 0xDEADBEEF2,

} ;

Queue QueueInit();

elem_t QueuePop(Queue* queue);

void _QueueLog(Queue* queue, int line, const char* func_name);

//add size, empty
//get elem(top) //check cppreference

#define QueueLog(queue) _QueueLog(queue, __LINE__, __PRETTY_FUNCTION__);

#endif