#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
// 题目：找到两个单链表相交的起点。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA, lenB = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        // 计算长度
        while(p) {
            lenA++;
            p = p->next;
        }
        while(q) {
            lenB++;
            q = q->next;
        }
        // 重置指针
        p = headA;
        q = headB;

        // 让p指代长边
        if(lenA < lenB) {
            swap(p, q);
            swap(lenA, lenB);
        }

        //对齐
        int offset = lenA - lenB;
        while(offset--) {
            p = p->next;
        }

        // 判相同
        while(p) {
            if(p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};

int main() {
    // 设计的输入不好，因为指针不同。
    //build two linked list
    std::ios_base::sync_with_stdio(false); // 让cin输入不会滞留
    int num;
    cin >> num;
    ListNode* headA = new ListNode(num);
    ListNode* p = headA;
    while(cin >> num && num != -1) {
        p->next = new ListNode(num);
        p = p->next;
    }

    cout << "Input the second linked list:" << endl;
    cin >> num;
    ListNode* headB = new ListNode(num);
    p = headB;
    while(cin >> num && num != -1) {
        p->next = new ListNode(num);
        p = p->next;
    }

    Solution s;
    ListNode *head = s.getIntersectionNode(headA, headB);

    //Print
    p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
}