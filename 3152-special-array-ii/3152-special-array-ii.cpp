class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>parity;
        for(int i=1;i<n;i++){
            if((nums[i]%2)==(nums[i-1]%2))
                parity.push_back(i-1);
        }
        vector<bool>result;
        for(auto it:queries){
            int left=it[0];
            int right=it[1];
            int l=0,r=parity.size()-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(parity[mid] <right && parity[mid]>=left){
                    result.push_back(false);
                    break;
                }
                else if(parity[mid] <left)
                    l=mid+1;
                else
                    r=mid-1;
            }
            if(l>r)
                result.push_back(true);
        }
        return result;
    }
};