class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>res;
        int n=nums.size();
        int mask=(1<<maximumBit)-1;
        vector<int>xOr;
        int temp=0;
        for(auto it:nums){
            temp^=it;
            xOr.push_back(temp);
        }
        while(n--)
            res.push_back(xOr[n]^mask);
        return res;
    }
};