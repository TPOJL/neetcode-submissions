/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast_p = dummy;
        ListNode* slow_p = dummy;

        while(n > 0){
            fast_p = fast_p->next;
            --n;
        }

        while(fast_p->next != nullptr){
            fast_p = fast_p->next;
            slow_p = slow_p->next;
        }

        ListNode* del = slow_p->next;
        slow_p->next = slow_p->next->next;
        delete del;

        head = dummy->next;
        
        return head;
    }
};
