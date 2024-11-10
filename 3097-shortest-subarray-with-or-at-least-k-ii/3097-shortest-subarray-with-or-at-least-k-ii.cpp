class Solution {
private:
    void updat(int num,vector<int>&set_bits){
        for(int i=0;i<32;i++){
            if((num&(1<<i)) > 0)
                set_bits[i]++;
        }
    }
    int get_number(vector<int>&set_bits){
        int sum=0;
        for(int i=0;i<32;i++){
            if(set_bits[i]>0){
                sum += pow(2,i);
            }
        }
        return sum;
    }
    void remove(int num,vector<int>&set_bits){
        for(int i=0;i<32;i++){
            if((num&(1<<i)) > 0)
                set_bits[i]--;
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0 || k==1)
            return 1;
        int n=nums.size();
        int left=0,right=0,sum=0;
        int res=INT_MAX;
        vector<int>set_bits(32,0);
        for(int right=0;right<n;right++){
            updat(nums[right],set_bits);
            while(get_number(set_bits) >= k){
                res=min(res,(right-left+1));
                remove(nums[left],set_bits);
                left++;
            }
        }
        return res!=INT_MAX?res:-1;
    }
};