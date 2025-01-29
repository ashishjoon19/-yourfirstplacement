class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int flag=0;
        int ind=-1,i;
        for(i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i]){
                    if(ind==-1)
                        ind=j;
                    else if(nums[j] < nums[ind])
                        ind=j;
                    flag=1;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            sort(nums.begin(),nums.end());
        else{
            swap(nums[i],nums[ind]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};