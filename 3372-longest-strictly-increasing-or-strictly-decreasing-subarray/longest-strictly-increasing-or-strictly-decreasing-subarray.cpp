class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        // if(n==1)
        //     return n;
        int res=1;
        int cnt=1;
        //first try for ascending order
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1])
                cnt++;
            else{
                res=max(res,cnt);
                cnt=1;
            }
        }
        res=max(cnt,res);
        cnt=1;
        //now try for descending order order
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1])
                cnt++;
            else{
                res=max(res,cnt);
                cnt=1;
            }
        }
        res=max(cnt,res);
        return res;
    }
};