class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        vector<vector<int>>result;
        for(int i=0;i<n-2;i++){
            for(int l=i+1;l<n;l++){
                int j=l+1,k=n-1;
                long long sum = target-(long long)(nums[i]+nums[l]);
                while(j<k){
                    if((long long)(nums[j]+nums[k]) < sum){
                        j++;
                    }
                    else if((long long)(nums[j]+nums[k]) > sum){
                        k--;
                    }
                    else{
                        res.insert({nums[i],nums[l],nums[j],nums[k]});
                        j++;
                        k--;
                    }
                }
            }    
        }
        for(auto it:res){
            result.push_back(it);
        }
        return result;
    }
};