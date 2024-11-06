class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        map<int,int>setbits;
        int n=nums.size();
        for(auto it:nums)
            setbits[it]=__builtin_popcount(it);

        int prev_maxi=-1;
        for(int i=0;i<n;i++){
            int mini=nums[i];
            int maxi=nums[i];
            while(i+1 < n && setbits[nums[i]]==setbits[nums[i+1]]){
                mini=min(mini,nums[i+1]);
                maxi=max(maxi,nums[i+1]);
                i++;
            }
            if(mini > prev_maxi){
                prev_maxi=maxi;
            }
            else
                return false;
        }
        return true;
    }
};