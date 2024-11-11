class Solution {
private:
    vector<int>is_prime;
    void sieve(){
        is_prime.resize(1001,-1);
        is_prime[0]=0;
        is_prime[1]=0;
        for(int i=2;i<=1000;i++){
            if(is_prime[i]!=-1){
                continue;
            }
            is_prime[i]=1;
            int j=2;
            while(i*j <= 1000){
                is_prime[i*j]=0;
                j++;
            }
        }
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        sieve();

        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1])
                continue;
            int j,flag=1;
            for(j=2;j<nums[i];j++){
                if(is_prime[j]){
                    if((nums[i]-j) < nums[i+1]){
                        nums[i]=nums[i]-j;
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)
                return false;
        }

        return true;
    }
};