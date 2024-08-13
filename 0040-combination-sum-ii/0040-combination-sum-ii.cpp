class Solution {
public:
    vector<vector<int>>res;
    void find(int start,int target,vector<int>temp,vector<int>&nums){
        if(target==0){    
            res.push_back(temp);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) break;
            
            temp.push_back(nums[i]);
            find(i + 1, target - nums[i], temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        find(0,target,temp,candidates);
        return res;
    }
};