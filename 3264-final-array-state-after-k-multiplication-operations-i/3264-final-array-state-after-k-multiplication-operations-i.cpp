class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        while(k--){
            int min=0;
            for(int i=1;i<n;i++){
                if(nums[i]<nums[min])
                    min=i;
            }
            nums[min]*=multiplier;
        }
        return nums;
    }
};