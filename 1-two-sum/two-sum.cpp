class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,vector<int>>m;
        int i=0;
        for(i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        for(auto it:nums){
            if(m[target-it].size() >= 1){
                if((target-it)==it && m[it].size()>=2)
                    return {m[it][0],m[it][1]};
                else if((target-it)==it) continue;
                else return {m[target-it][0],m[it][0]};
            }
        }
        return {};
    }
};