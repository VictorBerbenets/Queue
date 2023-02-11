#include "queue.h"

int main() {

    Queue queue = Queue_Init();

    for (int i = 0; i < 1000; i++) {
        Queue_Push(&queue, i);
    }
    Queue_Log(&queue);

    for (int i = 0; i < 1000; i++) {
        Queue_Pop(&queue);
    }

    Queue_Log(&queue);

    return 0;
}