/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return 0;
        ListNode*fast=head->next,*slow=head;
        while(slow && fast){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
            if(fast==slow) return 1;
        }
    return 0;
    }
};
