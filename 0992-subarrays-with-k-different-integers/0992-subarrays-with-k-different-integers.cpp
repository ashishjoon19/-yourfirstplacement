class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int,int>m;
        int n=nums.size();
        int res1=0,l=0,r=0,res2=0;
        int sum=0;
        while(l<=r && r<n){
            m[nums[r]]++;
            while(m.size() > k && l<=r){
                m[nums[l]]--;
                if(m[nums[l]]==0)
                    m.erase(nums[l]);
                l++;
            }
            res1+=r-l+1;
            r++;
        }
        k-=1;
        l=0,r=0;
        sum=0;
        map<int,int>m1;
        while(l<=r && r<n){
            m1[nums[r]]++;
            while(m1.size() > k && l<=r){
                m1[nums[l]]--;
                if(m1[nums[l]]==0)
                    m1.erase(nums[l]);
                l++;
            }
            res2+=r-l+1;
            r++;
        }
        return res1-res2;
    }
};