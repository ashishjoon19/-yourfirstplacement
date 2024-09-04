class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for(auto it:nums){
            if(it >= target)
                return 1;
        }

        int mini=INT_MAX;
        int i=0,j=0;
        long long sum=0;
        while(j<nums.size()){
            sum += nums[j];
            if(sum >= target){
                while(i<=j && sum>=target){
                    sum-=nums[i];
                    i++;
                }
                mini=min(mini,j-i+2);
            }
            j++;
        }
        if(mini==INT_MAX)
            return 0;
        return mini;
    }
};