class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        vector<vector<int>>result;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            int sum = -(nums[i]);
            while(j<k){
                if(nums[j]+nums[k] < sum){
                    j++;
                }
                else if(nums[j]+nums[k] > sum){
                    k--;
                }
                else{
                    res.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        for(auto it:res){
            result.push_back(it);
        }
        return result;
    }
};