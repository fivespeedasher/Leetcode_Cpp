#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
//题目：翻转链表中的每两个相邻的节点
//思路：用前一个位置去置换后两个位置
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next && cur->next->next) {
            ListNode* temp1 = cur->next;
            ListNode* temp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp1;
            temp1->next = temp2;
            cur = cur->next->next;
        }
        return dummy->next;
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
    head = s.swapPairs(head);

    //Print the linked list
    p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
}
