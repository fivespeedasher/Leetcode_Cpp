#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
// 题目：找到环的起点。
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                ListNode *index1 = slow;
                ListNode *index2 = head;
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};

int main() {
    // 建立一个环形链表
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution s;
    ListNode *res = s.detectCycle(head);
    std::cout << res->val << std::endl;
}