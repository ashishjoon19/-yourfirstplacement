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
    private:
    int find_gcd(int a,int b){
        int i=2,gcd=1;
        while(i<=a && i<=b){
            if(a%i==0 && b%i==0)
                gcd=i;
            i++;
        }
        return gcd;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==nullptr)
            return head;
        ListNode* next=head->next;
        ListNode*mainhead= head;
        while(next){
            int gcd=find_gcd(head->val,next->val);
            ListNode* temp=new ListNode(gcd);
            head->next=temp;
            temp->next=next;
            head=next;
            next=next->next;
        }
        return mainhead;
    }
};