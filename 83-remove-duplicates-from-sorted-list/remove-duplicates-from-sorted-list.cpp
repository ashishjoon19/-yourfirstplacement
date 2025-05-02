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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail=head;
        if(!tail) return tail;
        while(tail){
            ListNode* next=tail->next;
            if(!next) return head;
            if(tail->val==next->val){
                tail->next=next->next;
            }
            else
                tail=tail->next;
        }
        return head;
    }
};