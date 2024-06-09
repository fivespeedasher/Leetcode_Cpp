#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
private:
    struct Node{
        int key;
        Node* next;
        Node(int x): key(x), next(nullptr) {}
    };
    int KeyRange = 31;
    vector<Node *> bucket;
    int hash(int key) {
        return key % KeyRange;
    }
public:
    MyHashSet() {
        bucket = vector<Node *> (KeyRange); 
    }
    
    void add(int key) {
        int loc = hash(key);
        // 空链表添加
        if (bucket[loc] == nullptr) {
            bucket[loc] = new Node(key); 
            return;
        }
        // 判断contain
        auto temp = bucket[loc];
        if(temp->key==key) return;
        while((temp -> next != nullptr)) {
            if(temp -> next->key == key) return;
            temp = temp -> next;
        }
        //尾插
        temp->next = new Node(key);
        return;
        
    }
    
    void remove(int key) {
        int loc = hash(key);
        if(bucket[loc] == nullptr) return;
        auto temp =bucket[loc];
        // 头删除
        if (temp->key == key) {
            bucket[loc] = temp->next;
            delete temp;
        }
        else {
        // 
            while(temp->next != nullptr) {
                if(temp -> next -> key == key){
                    auto p = temp->next;
                    temp->next = p->next;
                    delete p;
                    break;
                }
                temp = temp->next;
            }
        }
        return;
    }
    
    bool contains(int key) {
        int loc = hash(key);
        if(bucket[loc] == nullptr) return false;
        auto temp = bucket[loc];

        while(temp){
            if(temp->key == key) return true;
            temp = temp->next;
        }
        
        return false;
    }
};

int main() {
    MyHashSet* myHashSet = new MyHashSet();
    myHashSet->add(1);      // set = [1]
    myHashSet->add(2);      // set = [1, 2]
    bool c1,c2,c3,c4;
    c1 = myHashSet->contains(1); // 返回 True
    c2 = myHashSet->contains(3); // 返回 False ，（未找到）
    myHashSet->add(2);      // set = [1, 2]
    c3 = myHashSet->contains(2); // 返回 True
    myHashSet->remove(2);   // set = [1]
    c4 = myHashSet->contains(2); // 返回 False ，（已移除）
    cout << c1 << c2 << c3 << c4 << endl;
}