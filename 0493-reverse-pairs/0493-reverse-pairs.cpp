class Solution {
public:
    int res;
    void mergesort(vector<int>&nums,int i,int j){
        if(i<j){
            int mid=(i+j)/2;
            mergesort(nums,i,mid);
            mergesort(nums,mid+1,j);
            merge(nums,i,mid,j);
        }
    }
    void merge(vector<int>&nums,int i,int mid,int j){
        vector<int>arr1;
        vector<int>arr2;
        for(int temp=i;temp<=mid;temp++)
            arr1.push_back(nums[temp]);
        for(int t=mid+1;t<=j;t++)
            arr2.push_back(nums[t]);
        int m=(mid-i+1),n=j-mid;
        int k=i,x=0,y=0;
        while (x < arr1.size()) {
            while (y < arr2.size() && (long long)arr1[x] > 2LL * arr2[y]) {
                y++;
            }
            res += y;
            x++;
        }
        x=0,y=0;
        while(x<m && y<n){
            if(arr1[x] < arr2[y])
                nums[k++]=arr1[x++];
            else
                nums[k++]=arr2[y++];
        }
        while(x<m)
            nums[k++]=arr1[x++];
        while(y<n)
            nums[k++]=arr2[y++];
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        res=0;
        
        mergesort(nums,0,n-1);

        return res;
    }
};