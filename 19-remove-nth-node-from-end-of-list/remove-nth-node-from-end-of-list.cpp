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
        int ttl_nodes=0;
        ListNode* temp=head;
        while(temp){
            ttl_nodes++;
            temp=temp->next;
        }
        n=ttl_nodes-n;
        if(n==0){
            return head->next;
        }
        n-=1;//2 1 0 
        temp=head;//1 2 3 5
        while(temp){
            if(n==0){
                temp->next=temp->next->next;
                return head;
            }
            n-=1;
            temp=temp->next;
        }
        return head;
    }
};