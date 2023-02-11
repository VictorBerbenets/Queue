#include "queue.h"

int main() {

    Queue queue = Queue_Init();

    for (int i = 0; i < 1026; i++) {
        Queue_Push(&queue, i);
    }

    Queue_Pop(&queue);
    Queue_Pop(&queue);
    Queue_Pop(&queue);
    Queue_Pop(&queue);
    Queue_Pop(&queue);

    Queue_Log(&queue);

    Queue_Push(&queue, 412);
    Queue_Push(&queue, 532);
    Queue_Push(&queue, 634);

    for (int i = 0; i < 1026; i++) {
        Queue_Pop(&queue);
    }

    Queue_Log(&queue);

    return 0;
}