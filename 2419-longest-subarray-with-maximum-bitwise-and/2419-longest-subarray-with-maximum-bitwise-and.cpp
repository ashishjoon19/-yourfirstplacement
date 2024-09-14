class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_cnt=0;
        int maxi=nums[0];
        int n=nums.size();
        for(auto it:nums)
            maxi=max(maxi,it);
        
        int c=0;
        for(auto it:nums){
            if(it==maxi){
                c++;
                max_cnt=max(max_cnt,c);
            }
            else
                c=0;
        }
        return max_cnt;
    }
};