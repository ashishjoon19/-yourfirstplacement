class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int len=a.size();
        int left=1,right=len-2,mid;
        if(len == 1)
            return 0;
        if(a[0]>a[1])
            return 0;
        if(a[len-1]>a[len-2])
            return len-1;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(a[mid] > a[mid-1] && a[mid] >a[mid+1])
                return mid;
            else if (a[mid]>a[mid-1])
                left=mid+1;
            else
                right=mid-1;
        }
        return -1;
    }
};