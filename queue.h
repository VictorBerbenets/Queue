#ifndef Queue_Struct
#define Queue_Struct

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "validator.h"
#include <iostream>

using namespace std;

typedef double elem_t;

const short Queue_Size     = 1024;
const short Tail_max_value = Queue_Size - 1;

class Queue {
private:
    short tail;
    short head;
    elem_t* data;
    size_t size;
    size_t capacity;

public:
    Queue (int queue_size) {

        this->data = new elem_t[queue_size];
        this->tail = 0;
        this->head = 0;
        this->capacity = queue_size;
        this->size     = 0;
    }
    void SeTtail(short tail) {
        this->tail = tail;
    }
    void SeThead(short head) {
        this->head = head;
    }
    short GeTtail() {
        return tail;
    }
    short GeThead() {
        return head;
    }
    size_t GeTsize() {
        return size;
    }
    size_t GeTcapacity() {
        return capacity;
    }
    void SeTsize(int value) {
        this->size = value;
    }
    void SeTdata_value(int value_id, elem_t value) {
        this->data[value_id] = value;
    }
    elem_t GeTdata_value(int value_id) {
        return this->data[value_id];
    } 
    ~Queue () {
        delete [] this->data;
        this->tail = 0;
        this->tail = 0;
        this->capacity = 0;
        this->size     = 0;

    }
};

enum Queue_Errors {
    
    INVALID_DATA_SIZE = 0xDEADBEEF1,
    INVALID_POP_VALUE = 0xDEADBEEF2,

} ;

Queue Queue_Init();

void Queue_Push(Queue* queue, elem_t value);

elem_t Queue_Pop(Queue* queue);

void _Queue_Log(Queue* queue, int line, const char* func_name);

//add size, empty
//get elem(top) //check cppreference

#define Queue_Log(queue) _Queue_Log(queue, __LINE__, __PRETTY_FUNCTION__);

#endif