#include <iostream>
using namespace std;

class MyLinkedList {
public:
//题目：设计链表的创建、第n个节点、头插、尾插、第n个节点前插、删除第n个节点的操作
//采用虚拟头节点
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int x): val(x), next(NULL) {}
    };

    MyLinkedList() { 
        _dummyHead = new LinkedNode(0); // 私有变量命名
        _size = 0;
    }
    
    int get(int index) {
        if(index > _size - 1 || index < 0) {
            return -1;
        }
        LinkedNode* p = _dummyHead;
        for(int i = 0; i <= index; i++) {
            p = p->next;
        }
        return p->val;

    }
    
    void addAtHead(int val) {
        LinkedNode* p = new LinkedNode(val);
        p->next = _dummyHead->next;
        _dummyHead->next = p;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* p = _dummyHead;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = new LinkedNode(val);
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size || index < 0) {
            return;
        }
        else if(index == _size) {
            addAtTail(val);
            return;
        }
        else {
            LinkedNode* p = _dummyHead;
            for(int i = 0; i < index; i++) {  //最后一次执行i=index-1, 结束后i=index
                p = p->next;
            }
            LinkedNode* temp = new LinkedNode(val);
            temp->next = p->next;
            p->next = temp;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index > _size - 1 || index < 0) {
            return;
        }
        LinkedNode* p = _dummyHead;
        for(int i = 0; i < index; i++) { //可以去考虑我需要进行几次迭代，再算for的次数，来定终止条件
            p = p->next;
        }
        LinkedNode* temp = p->next;
        p->next = p->next->next;
        delete temp;
        _size--;
    }
private:
    LinkedNode* _dummyHead;
    int _size;
};

int main() {
    MyLinkedList l;
    l.addAtHead(5);
    l.addAtIndex(1, 2);
    cout << l.get(1) << endl;
    l.addAtHead(6);
    l.addAtTail(2);
    cout << l.get(3) << endl;
    l.addAtTail(1);
    cout << l.get(5) << endl;
    l.addAtHead(2);
    cout << l.get(2) << endl;
    l.addAtHead(6);
}
/**
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3
 */