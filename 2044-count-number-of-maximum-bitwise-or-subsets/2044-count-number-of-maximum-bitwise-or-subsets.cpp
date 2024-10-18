class Solution {
public:
    int res;
    void find(int sum,int &maxi,vector<int>&nums,int idx){
        if(sum==maxi && idx==nums.size())
            res++;
        if(idx >= nums.size())
            return;
        find(sum|nums[idx],maxi,nums,idx+1);
        find(sum,maxi,nums,idx+1);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        res=0;
        int maxi=0;
        for(auto it:nums)
            maxi=maxi|it;
        
        find(0,maxi,nums,0);
        return res;
    }
};