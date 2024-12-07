class Solution {
private:
    bool find(int mid,vector<int> nums, int opn){
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]>mid){
                opn-=(nums[i]/mid);
                if(nums[i]%mid==0)
                    opn+=1;
                if(opn<0)
                    return false;
            }
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // 1- maxvalue
        int right=1,left=1;
        for(auto it:nums)
            right=max(right,it);
        
        int res=right;
        while(left<=right){
            int mid=(left+right)/2;
            if(find(mid,nums,maxOperations)){
                res=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return res;
    }
};