#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}

};



class Solution {
    public:
    //题目：移除链表元素
    //边界选取：先左开右开地选头节点，再左闭右开地先下一节点。
        ListNode* removeElements(ListNode* head, int val) {
            if(head == NULL) {
                return head;
            }
            while(head->val == val) {
                head = head->next;
                if(head == NULL) return head;
            }
            ListNode* new_h = head;
            ListNode* p = head;
            while(p->next != NULL) {
                if(p->next->val == val) {
                    p->next = p->next->next;
                }
                else p = p->next;
            }
            return new_h;
        }
};

int main() {
    Solution s;

    // Build a linked list
    int num;
    cin >> num;
    ListNode* head = new ListNode(num);
    ListNode*p = head;
    while(cin >> num) {
        ListNode* q = new ListNode(num);
        p->next = q;
        p = q;
    }

    // Remove elements
    int val = 6;
    head = s.removeElements(head, val);
    
    // Print the linked list
    while(head != NULL) {
        cout << head->val << " - ";
        head = head->next;
    }
}