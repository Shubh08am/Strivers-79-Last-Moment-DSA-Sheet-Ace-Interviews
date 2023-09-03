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
    ListNode* middleNode(ListNode* head) {
        /*
        BRUTE 
        T.C ->  O(N) [LENGTH]  + O(N/2) [go to middle] 
        SC -> O(1) 

        OPTIMIZED 
        FAST AND SLOW 
        T.C -> O(N/2) 
        S.C-> O(1)
        */
    /*  ListNode*slow=head,*fast=head->next; 
        while(slow&&fast){
            slow=slow->next;
            fast=fast->next;
            if(fast)  fast=fast->next;
        }
    return slow;
    */
    ListNode*slow=head,*fast=head; 
        while(slow&&fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast->next)  fast=fast->next;
        }
    return slow;
    /*
    ListNode*slow=head , *fast=head; 
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    */
    }
};
