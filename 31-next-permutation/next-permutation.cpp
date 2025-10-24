class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
// 2 1 4 3 5
// 2 1 4 5 3 
// 2 1 5 4 3 -> 2 1 5 3 4
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                i-=1;
                int smallest=i+1;
                for(int j=i+1;j<n;j++){
                    if(arr[j]< arr[smallest] && arr[j] > arr[i]){
                        smallest=j;
                    }
                }
                swap(arr[i],arr[smallest]);
                sort(arr.begin()+i+1,arr.end());
                return;
            }
        }
        sort(arr.begin(),arr.end());
    }
};