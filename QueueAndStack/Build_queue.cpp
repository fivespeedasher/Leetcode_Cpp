#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> queue;
    int head;
    int tail;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        head = -1;
        tail = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        tail = (tail + 1) % queue.size();
        queue[tail] = value;
        if(head == -1) head = 0;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(head == tail) {
            head = -1;
            tail = -1;
        }
        else head = (head+1) % queue.size();
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else return queue[head];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else return queue[tail];
    }
    
    bool isEmpty() {
        if(head == -1 & tail == -1) return true;
        else return false;
    }
    
    bool isFull() {
        if(head == (tail+1) % queue.size()) return true;
        else return false;
    }
};

int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    obj->enQueue(1);
    bool param_2 = obj->deQueue();
    obj->enQueue(2);
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
}