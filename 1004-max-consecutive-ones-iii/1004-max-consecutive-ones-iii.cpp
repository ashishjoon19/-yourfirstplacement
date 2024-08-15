class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones=0,zero=0,l=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ones++;
                res=max(res,ones+zero);
                continue;
            }
            res=max(res,ones+zero);
            zero++;
            while(zero > k){
                if(nums[l]==0)
                    zero--;
                else
                    ones--;
                l++;
            }
            // res=max(res,ones+zero);
        }
        res=max(res,ones+zero);
        return res;
    }
};