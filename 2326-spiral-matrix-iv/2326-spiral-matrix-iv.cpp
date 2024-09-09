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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        int k=0,i=0,j=0;
        while(head){
            for(j=k;j<=n-1-k;j++){
                if(head==nullptr)
                    return res;
                res[i][j]=head->val;
                head=head->next;
            }
            j--;
            for(i=k+1;i<=m-1-k;i++){
                if(head==nullptr)
                    return res;
                res[i][j]=head->val;
                head=head->next;
            }
            i--;
            for( j=n-1-k-1;j>=k;j--){
                if(head==nullptr)
                    return res;
                res[i][j]=head->val;
                head=head->next;
            }
            j++;
            for( i=m-1-k-1;i>=1+k;i--){
                if(head==nullptr)
                    return res;
                res[i][j]=head->val;
                head=head->next;
            }
            i++;
            k++;
        }
        return res;
    }
};