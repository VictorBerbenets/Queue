#include "queue.h"


void Queue::QueuePush(Queue* queue, elem_t value) {

    Validator(!((queue->GetTail() == queue->GetHead()) && (queue->GetSize() != 0)), fprintf(stderr, "\t| " Blue " \tQueue is overflow: you"
    "can't push elements in queue." Grey "\n\t|\n"); return ;);

    queue->Push(value);
    queue->SetSize(queue->GetSize() + 1);
    queue->SetTail(queue->GetTail() + 1);
    queue->SetTail(queue->GetTail() & Tail_max_value);
}

elem_t Queue::QueuePop(Queue* queue) {

    Validator(queue->GetSize() != 0, fprintf(stderr, "\t| " Blue " \tQueue is empty: you can't pop elements from queue." Grey "\n\t|\n"
    ""); return 87;);
    
    elem_t ret_value = queue->GetDataValue(queue->GetHead());
    Validator (ret_value >= 0, fprintf(stderr, "\t| " Blue " \tThere can be only positive number in queue." Grey "\n\t|\n");
    return 96;);

    queue->SetHead(queue->GetHead() + 1);

    queue->SetHead(queue->GetHead() & Tail_max_value);
    queue->SetSize(queue->GetSize() - 1);

    return ret_value;
}

void Queue::_QueueLog(Queue* queue, int line, const char* func_name) {

    FILE* Log_Queue = fopen("log_queue.txt", "a");
    Validator(Log_Queue != nullptr, exit(EXIT_FAILURE));

    fprintf(Log_Queue, "\n*****************************************************Queue_Info********************************************"
    "*****************************************\n");
    
    fprintf(Log_Queue, "%s was called from '%d' line and function: '%s'\n", __FUNCTION__, line, func_name);
    fprintf(Log_Queue, "queue's tail      = %d\n", queue->GetTail());
    fprintf(Log_Queue, "queue's head      = %d\n", queue->GetHead());
    fprintf(Log_Queue, "queue's size      = %zd\n", queue->GetSize());
    fprintf(Log_Queue, "queue's capacity  = %zd\n", queue->GetCapacity());
    fprintf(Log_Queue, "        Queue elemenst:\n");

    for (size_t number = 0; number < queue->GetSize(); number++) {
        fprintf(Log_Queue, "[%zd] = %lg\n", queue->GetHead() + number, queue->GetDataValue(queue->GetHead()) + number);
    }

    fprintf(Log_Queue, "**************************************************************************************************************"
    "**************************************\n\n");
    char is_file_close = fclose(Log_Queue);
    Validator(is_file_close == 0, exit(EXIT_FAILURE));
}

void Queue::SetTail(short tail) {
    tail_ = tail;
}

void Queue::SetHead(short head) {
    this->head_ = head;
}

short Queue::GetTail() {
    return tail_;
}

short Queue::GetHead() {
    return head_;
}

size_t Queue::GetSize() {
    return size_;
}

size_t Queue::GetCapacity() {
    return capacity_;
}

void Queue::SetSize(int value) {
    this->size_ = value;
}

void Queue::Push(elem_t value) {
    this->data_[this->tail_] = value;
}

elem_t Queue::GetDataValue(int value_id) {
    return this->data_[value_id];
}
