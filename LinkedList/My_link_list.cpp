#include <iostream>
using namespace std;
class MyLinkedList {
public:
    struct node{
        int val;
        node* next;
        node(int x):val(x), next(NULL) {}
    };
    node* head;
    int size;
    //head节点 留空（0）
    MyLinkedList() {
        head = new node(0); 
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0)
            return -1;
        node* p = head;
        while(index >= 0){
            index--;
            p = p->next;
        }
        return p->val;
    }
    void addAtHead(int val) {
        node* temp = new node(val);
        temp->next = head->next;
        head->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        node* p = head;
        node* n = new node(val);
        while(p->next != NULL){
            p = p->next;
        }
        p->next = n;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index <0)
            return;
        node* n = new node(val);
        node* p = head;
        for(int i=0; index > i; i++){
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        node *p = head;
        node *del;
        for(int i=0; i < index; i++){
            p = p->next;
        } 
        del = p->next;
        p->next = del->next;
        delete del; //对应new
        size--;
    }

    void pprint(){
        node *p = head;
        for(int i=0; i <= size; i++){
            cout << p->val <<endl;
            p = p->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList* obj = new MyLinkedList();
    
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->pprint();
    cout << endl;
    int param_0 = obj->get(1);
    obj->deleteAtIndex(1);
    int param_1 = obj->get(1);
    obj->pprint();
    cout << endl << param_0 << endl;
    cout <<param_1;

}

