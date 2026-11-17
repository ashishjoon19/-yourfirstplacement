class Solution {
    private:
    int MOD=1000000000+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        //create leftnextminimumindex array
        vector<int>lnm;
        lnm.push_back(-1);
        for(int i=1;i<n;i++){
            int prev=i-1;
            while(prev!=-1 && arr[i]<=arr[prev]){
                prev=lnm[prev];
            }
            lnm.push_back(prev);
        }
        //create rightnextminimumindex array
        vector<int>rnm(n,-1);
        for(int i=n-2;i>=0;i--){
            int prev=i+1;
            while(prev!=-1 && arr[i]<arr[prev]){
                prev=rnm[prev];
            }
            rnm[i]=(prev);
        }
        //now we have lnm and rnm
        int res=0;
        for(int i=0;i<n;i++){
            int left = i-lnm[i]-1;
            int right = rnm[i]-i-1;
            if(rnm[i]==-1)
                right=n-i-1;
            long long l = left;
            long long r = right;
            long long val = arr[i];

            int ans = (int)((((l + r) % MOD + (l * r) % MOD + 1) % MOD * val) % MOD);

            res=(res+ans)%MOD;
        }
        return res;
    }
};
/*
3,0

pretty good question
[3,1,2,4]
-> find the index of next left smaller than current 
-> similiarly find the index of the next right smaller than current

this will give us how many subarrays are there whose minimum is current

[-1,-1,1,2]left
[1,-1,-1,-1]right

1*3+(1+2+1*2+1=5)6*1+(1+0+1+1*0=2)2*2+(0+0+0*0+1)1*4
3+6+4+4=17


how to find lnm and rnm

[3,1,2,4]
[-1,-1,1,2]
no need any monotonic stack we will ask our leftmost indexed element what's its next smaller if it is smaller than current then stop if not then go to its nect smaller too until u will reach to either -1 or element smaller than current 

calculation 
current index=i;
((i-lnm[i]-1)left + (rnm[i]-1)right + left*right + 1)*arr[i] 




11,81,94,43,3
[-1,0,1,0,-1]
[0,0,0,,-1]

*/