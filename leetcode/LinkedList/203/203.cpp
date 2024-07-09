#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};



class Solution {
    public:
    //题目：移除链表元素
    //边界选取：先左开右开地选头节点，再左闭右开地先下一节点。
        ListNode* removeElements1(ListNode* head, int val) {
            if(head == NULL) {
                return head;
            }
            while(head->val == val) {
                ListNode* temp = head;
                head = head->next;
                delete temp; // 释放内存
                if(head == NULL) return head;
            }
            ListNode* p = head;
            while(p->next != NULL) {
                if(p->next->val == val) {
                    ListNode* temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                }
                else p = p->next;
            }
            return head;
        }

    // 安置一个虚拟头节点，这样就不用考虑头节点的问题了
        ListNode* removeElements(ListNode* head, int val) {
            //if(head == nullptr) return head;
            ListNode* dummyHead = new ListNode(0, head);
            ListNode* p = dummyHead;
            ListNode* temp;
            while(p->next != NULL) {
                if(p->next->val == val) {
                    temp = p->next;
                    p->next = temp->next;
                    delete temp;
                }
                else p = p->next;
            }
            head = dummyHead->next;
            delete dummyHead;
            return head;
    }
};

int main() {
    Solution s;

    // Build a linked list
    int num;
    cin >> num;
    ListNode* head = new ListNode(num);
    ListNode* p = head;
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