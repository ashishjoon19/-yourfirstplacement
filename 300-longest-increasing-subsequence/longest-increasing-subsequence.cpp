class Solution {
private:
    int res;
    vector<int>dp;
    int find(int i,vector<int>&nums,int &n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int sum=0;
        for(int j=i+1;j<n;j++){
            if(nums[j]>nums[i]){
                sum=max(sum,1+find(j,nums,n));
            }
        }
        dp[i]=sum;
        return sum;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        res=0;
        int n=nums.size();
        dp.resize(n,-1);
        for(int i=0;i<n;i++){
            res=max(res,1+find(i,nums,n));
        }
        return res;
    }
};