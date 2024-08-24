class Solution {
    public :
    int numberOfSubarrays(vector<int>nums, int k) {
        map<int,int>m;
        m[0]=1;
        int res=0,sum=0;
        for(auto it:nums){
            if(it%2!=0)
                sum++;
            if(sum-k==0)
                res+=m[0];
            else if(m.find(sum-k)!=m.end())
                res+=m[sum-k];
            m[sum]++;
        }
        return res;
    }
};