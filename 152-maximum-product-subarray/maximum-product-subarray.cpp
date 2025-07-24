class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        int ttl_odd=0;
        if(nums[0]<0)
            ttl_odd++;
        pre[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)
                ttl_odd++;
            if(nums[i]==0){
                pre[i]=0;
            }
            if(pre[i-1]==0)
                pre[i]=nums[i];
            else
                pre[i]=nums[i]*pre[i-1];
            res=max(res,nums[i]);
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0)
                suf[i]=0;
            if(suf[i+1]==0)
                suf[i]=nums[i];
            else
                suf[i]=nums[i]*suf[i+1];
        }
        for(int i=0;i<n;i++){
            cout<<pre[i]<<" "<<suf[i]<<endl;
        }
        // if(ttl_odd%2==0){
        //     //even case
        //     int sum=1;
        //     for(int i=0;i<n;i++){
        //         if(nums[i]==0) sum=1;
        //         else{
        //             sum*=nums[i];
        //             res=max(res,sum);
        //         } 
        //     }
        //     return res;
        // }
        // else{
            //odd case
            for(int i=0;i<n;i++){
                // if(nums[i]<=0){
                //     if(i!=0)
                //         res=max(pre[i-1],res);
                //     if(i+1<n)
                //         res=max(res,suf[i+1]);
                // }
                res=max(res,pre[i]);
                res=max(res,suf[i]);
            }
            return res;
        // }
    }
};