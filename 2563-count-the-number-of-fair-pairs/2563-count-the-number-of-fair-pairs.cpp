class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n;i++){
            int l=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);
            int r=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);
            int y=l-1-i;
            int x=r-1-i;
            res+=(r-l);
        }
        return res;
    }
};