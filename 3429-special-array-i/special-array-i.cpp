class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        int parity=1;
        if(nums[0]%2==0)
            parity=0;
        for(int i=0;i<n;i++){
            if(parity!=(nums[i]%2))
                return false;
            parity=1-parity;
        }
        return true;
    }
};