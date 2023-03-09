#include "queue.h"

template <typename T1, typename T2, typename T3>
void fuck(T1 &x, T2 &y, T3 &z) {

    x *= 2;
    y +=  2;
    z -=2;

    cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;

}

int main() {
    
    // double x = 523.52;
    // int y = 0;
    // double z = 523.52;


    // fuck(x, y, z);
    // int size = 0;
    // cin >> size;

    // int* ptr = new int[size];

    // for (int i = 0; i < size; i++) {
    //     *(ptr + i) = i*10;
    //     cout << "[] = "<< *(ptr + i) << endl;
    // }
    // cout << ptr <<endl;

    // delete [] ptr;
    Queue queue(1024);

    const int size = 1001;
    
    for (int i = 0; i < size; i++) {
        Queue_Push(&queue, i);
    }

    Queue_Log(&queue);

    Queue_Push(&queue, 412);
    Queue_Push(&queue, 532);
    Queue_Push(&queue, 634);

    for (int i = 0; i < size; i++) {
        Queue_Pop(&queue);
    }

    Queue_Pop(&queue);


    Queue_Log(&queue);

    return 0;
}

