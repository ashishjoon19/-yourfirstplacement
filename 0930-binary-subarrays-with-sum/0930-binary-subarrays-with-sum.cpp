class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0,r=0,n=nums.size();
        int sum=0,res=0;
        map<int,int>m;
        m[0]=1;
        for(auto it:nums){
            sum+=it;
            if(sum-goal==0)
                res+=m[0];
            else if(m.find(sum-goal)!=m.end())
                res+=m[sum-goal];
            m[sum]++;
        }
        return res;
    }
};