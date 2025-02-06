class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<long long,int>m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]!=nums[j])
                    m[nums[i]*nums[j]]++;
            }
        }
        int res=0;
        for(auto it:m){
            if(it.second>1)
                res+=(it.second*(it.second-1))/2;
        }
        return 8*res;
    }
};