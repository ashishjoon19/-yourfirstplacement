class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>m;
        for(auto it:nums)
            m[it]=1;
        
        ListNode* temp=head,*pre=nullptr;
        while(temp!=nullptr){
            if(m.find(temp->val)!=m.end()){
                if(temp==head){
                    head=head->next;
                    ListNode* p=temp;
                    temp=temp->next;
                    delete(p);
                }
                else{
                    pre->next=temp->next;
                    ListNode* p=temp;
                    temp=temp->next;
                    delete(p);
                }
            }
            else{
                pre=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};