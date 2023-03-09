#include "queue.h"


void Queue_Push(Queue* queue, elem_t value) {

    Validator(!((queue->GeTtail() == queue->GeThead()) && (queue->GeTsize() != 0)), fprintf(stderr, "\t| " Blue " \tQueue is overflow: you"
    "can't push elements in queue." Grey "\n\t|\n"); return ;);

    queue->SeTdata_value(queue->GeTtail(), value);
    queue->SeTsize(queue->GeTsize() + 1);
    queue->SeTtail(queue->GeTtail() + 1);
    queue->SeTtail(queue->GeTtail() & Tail_max_value);
    fprintf(stderr, "line = %d\n", __LINE__);
}

elem_t Queue_Pop(Queue* queue) {

    Validator(queue->GeTsize() != 0, fprintf(stderr, "\t| " Blue " \tQueue is empty: you can't pop elements from queue." Grey "\n\t|\n"
    ""); return 87;);
    
    elem_t ret_value = queue->GeTdata_value(queue->GeThead());
    Validator (ret_value >= 0, fprintf(stderr, "\t| " Blue " \tThere can be only positive number in queue." Grey "\n\t|\n");
    return 96;);

    queue->SeTdata_value(queue->GeThead(), queue->GeTdata_value(queue->GeThead()) * (-1));
    queue->SeThead(queue->GeThead() + 1);

    queue->SeThead(queue->GeThead() & Tail_max_value);
    queue->SeTsize(queue->GeTsize() - 1);

    return ret_value;
}

void _Queue_Log(Queue* queue, int line, const char* func_name) {

    FILE* Log_Queue = fopen("log_queue.txt", "a");
    Validator(Log_Queue != nullptr, exit(EXIT_FAILURE));

    fprintf(Log_Queue, "\n*****************************************************Queue_Info********************************************"
    "*****************************************\n");
    
    fprintf(Log_Queue, "%s was called from '%d' line and function: '%s'\n", __FUNCTION__, line, func_name);
    fprintf(Log_Queue, "queue's tail      = %d\n", queue->GeTtail());
    fprintf(Log_Queue, "queue's head      = %d\n", queue->GeThead());
    fprintf(Log_Queue, "queue's size      = %zd\n", queue->GeTsize());
    fprintf(Log_Queue, "queue's capacity  = %zd\n", queue->GeTcapacity());
    fprintf(Log_Queue, "        Queue elemenst:\n");

    for (size_t number = 0; number < queue->GeTsize(); number++) {
        fprintf(Log_Queue, "[%zd] = %lg\n", queue->GeThead() + number, queue->GeTdata_value(queue->GeThead()) + number);
    }

    fprintf(Log_Queue, "**************************************************************************************************************"
    "**************************************\n\n");
    char is_file_close = fclose(Log_Queue);
    Validator(is_file_close == 0, exit(EXIT_FAILURE));
}


