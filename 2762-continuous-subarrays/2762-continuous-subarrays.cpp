class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res=0;
        map<int,int>m;
        int n=nums.size(),i=0,j=0;

        while(j<n){
            m[nums[j]]++;
            while(abs((m.begin()->first)-(m.rbegin()->first))>2){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
            }
            res+=(j-i+1);
            j++;
        }
        return res;
    }
};