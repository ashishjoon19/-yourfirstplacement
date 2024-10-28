class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        map<long long,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i;
            int cnt=1;
            long long val=nums[i];
            while(m.find(val*val)!=m.end()){
                val=val*val;
                cnt++;
            }
            res=max(res,cnt);
        }
        if(res<=1)
            return -1;
        return res;
    }
};