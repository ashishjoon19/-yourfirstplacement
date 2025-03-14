class Solution {
private:
    bool check(int mid,vector<vector<int>>& q,vector<int>& nums){
        int n=nums.size();
        vector<int>temp(n,0);
        for(int i=0;i<=mid;i++){
            int l=q[i][0];
            int r=q[i][1];
            int val=q[i][2];
            temp[l]+=val;
            
            if((r+1)<n)
                temp[r+1]+=(-val);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=temp[i];
            temp[i]=sum;
            if((nums[i]-temp[i])>0) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int res=0,cnt=0;
        for(auto it:nums){
            if(it==0) cnt++;
        }
        if(cnt==n) return res;
        res=-2;
        int left=0,right=queries.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(check(mid,queries,nums)){
                res=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return res+1;
    }
};