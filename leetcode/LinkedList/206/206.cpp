#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
// 题目：反转链表
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main() {
    //build a linked list
    int num;
    ListNode* head  = new ListNode(0);
    ListNode* p  = head;
    while(cin >> num) {
        ListNode* temp = new ListNode(num);
        p->next =temp;
        p = temp;
    }

    Solution s;
    head= s.reverseList(head);

    //print the linked list
    p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
}