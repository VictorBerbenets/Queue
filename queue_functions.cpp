#include "queue.h"

Queue Queue_Init() {

    Queue queue     = {};

    queue.data_size = 0;
    queue.head      = 0;
    queue.tail      = 0;

    return queue;
}

void Queue_Push(Queue* queue, Data value) {

    Validator(!((queue -> tail == queue -> head) && (queue -> data_size != 0)), fprintf(stderr, "\t| " Blue " \tQueue is overflow: you"
    "can't push elements in queue." Grey "\n\t|\n"); return ;);

    queue -> data[queue -> tail] = value;
    queue -> data_size ++;
    queue -> tail      ++;
    queue -> tail = queue -> tail & Tail_max_value;
}

Data Queue_Pop(Queue* queue) {

    Validator(queue -> data_size, fprintf(stderr, "\t| " Blue " \tQueue is overflow: you can't pop elements from queue." Grey "\n\t|\n"
    ""); return INVALID_DATA_SIZE;);
    
    Data ret_value = queue -> data[queue -> head];
    Validator (ret_value >= 0, fprintf(stderr, "\t| " Blue " \tThere can be only positive number in queue." Grey "\n\t|\n");
    return INVALID_POP_VALUE;);

    queue -> data[queue -> head] *= -1;
    queue -> head ++;
    queue -> head = queue -> head & Tail_max_value;
    queue -> data_size --;
    return ret_value;
}

void _Queue_Log(Queue* queue, int line, const char* func_name) {

    FILE* Log_Queue = fopen("log_queue.txt", "a");
    Validator(Log_Queue != nullptr, exit(EXIT_FAILURE));

    fprintf(Log_Queue, "\n*****************************************************Queue_Info********************************************"
    "*****************************************\n");
    
    fprintf(Log_Queue, "%s was called from '%d' line and function: '%s'\n", __FUNCTION__, line, func_name);
    fprintf(Log_Queue, "queue's tail      = %d\n", queue -> tail);
    fprintf(Log_Queue, "queue's head      = %d\n", queue -> head);
    fprintf(Log_Queue, "queue's data_size = %zd\n", queue -> data_size);
    for (size_t number = 0; number < queue -> data_size; number++) {
        fprintf(Log_Queue, "[%zd] = %lg\n", queue -> head + number, queue -> data[queue -> head + number]);
    }

    fprintf(Log_Queue, "**************************************************************************************************************"
    "**************************************\n\n");
    char is_file_close = fclose(Log_Queue);
    Validator(is_file_close == 0, exit(EXIT_FAILURE));
}


