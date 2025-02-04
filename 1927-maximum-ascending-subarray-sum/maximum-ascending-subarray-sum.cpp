class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1]){
                res=max(res,sum);
                sum=nums[i];
            }
            else
                sum+=nums[i];
        }
        res=max(res,sum);
        return res;
    }
};