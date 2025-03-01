class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int cnt=0,n=nums.size();
        vector<int>res;
        for(int i=0;i+1<n;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
                i++;
            }
        }
        for(auto it:nums){
            if(it!=0)
                res.push_back(it);
        }
        cnt=n-res.size();
        while(cnt--)
            res.push_back(0);

        return res;
    }
};