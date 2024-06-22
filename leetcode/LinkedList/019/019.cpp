#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    //题目：删除链表中倒数第n个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = n;
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* i= dummyhead;
        ListNode* j = dummyhead;
        //ListNode* j = dummyhead;
        while(k--) { //先判k再--
            if(j->next == NULL) { //如果大于链表直接返回
                return head;
            }
            j = j->next;
        }
        while(j->next) {
            i = i->next;
            j = j->next;
        }
        ListNode* temp = i->next;
        i->next = i->next->next;
        delete temp;
        return dummyhead->next;
    }
};

int main() {
    //build a linked list
    int num;
    cin >> num;
    ListNode* head = new ListNode(num);
    ListNode* p = head;
    while(cin >> num) {
        p->next = new ListNode(num);
        p = p->next;
    }

    Solution s;
    head = s.removeNthFromEnd(head,1);

    //Print
    p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
}