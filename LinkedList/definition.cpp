#include <iostream>
using namespace std;

struct SinglyListNode;
SinglyListNode* head_insert(SinglyListNode* head, int data);

//Definition for singly-linked list.
struct SinglyListNode{
    int val;
    SinglyListNode* next;
    SinglyListNode(int x) : val(x),next(NULL) {}
};



SinglyListNode* insert(SinglyListNode* head, int data, int index){
    if(index == 0){
        head = head_insert(head, data);
        return head;
    }
    SinglyListNode* p = head;
    SinglyListNode* q = new SinglyListNode(data);
    while (index-1 > 0 && p->next != NULL)
    {
        p = p->next;
        index--;
    }
    q->next = p->next->next;
    p->next = q;
    return head;
}

SinglyListNode* head_insert(SinglyListNode* head, int data){
    SinglyListNode* q = new SinglyListNode(data);
    q->next = head;
    head = q;
    return head;
}

SinglyListNode* node_remove(SinglyListNode* head, int index){
    //头部删除
    if(index == 0){
        SinglyListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    SinglyListNode* p = head; 
    while (index != 0 && p->next->next != NULL)
    {
        p = p->next;
        index--;
    }

    //尾删除
    if(p->next->next == NULL && index == 1){
        free(p->next);
        p->next = NULL;
        return head;
    }

    //内部删除
    else if(index == 0){
        p->val = p->next->val;
        SinglyListNode* temp = p->next;
        p->next = p->next->next;
        free(temp);
        return head;
    }

    else{
        return head;
    }
}

int pprint(SinglyListNode* head){
    if(head == NULL){
        return 0;
    }

    else{
        if(head->next == NULL){
            cout << head->val <<endl;
            return 0;
        }
        else{
            cout << head->val <<endl;
            return pprint(head->next);
        }
    }
}
    
    

int main(){
    //Build a list
    int num;
    cin >> num;
    SinglyListNode* head = new SinglyListNode(num);
    SinglyListNode* p = head;

    while (cin >> num)
    {
        SinglyListNode* q = new SinglyListNode(num);
        p->next = q; //结构体指针(地址传递)用->, 结构体对象(值传递)用.
        p = p->next;    
    }
    

    //insert
    head = insert(head, 1, 0);

    //remove
    head = node_remove(head, 3);

    //print List
    pprint(head);

    return 0;

}

