#include "queue.h"

int main() {
    
    Queue queue(1024);

    const int size = 1001;
    
    for (int i = 0; i < size; i++) {
        queue.QueuePush(&queue, i);
    }

    queue.QueueLog(&queue);

    queue.QueuePush(&queue, 412);
    queue.QueuePush(&queue, 532);
    queue.QueuePush(&queue, 634);

    for (int i = 0; i < size; i++) {
        queue.QueuePop(&queue);
    }

    queue.QueuePop(&queue);


    queue.QueueLog(&queue);

    return 0;
}

