class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>vec(n,0);
        if(k==0)
            return vec;
        for(int i=0;i<n;i++){
            if(k>0){
                int j=i+1;
                int sum=0;
                int cnt=0;
                while(1){
                    if(j==n)
                        j=0;
                    sum+=code[j];
                    cnt++;
                    if(cnt==k)
                        break;
                    j++;
                }
                vec[i]=sum;
            }
            else if(k<0){
                k=(-1)*k;
                int j=i-1;
                int sum=0;
                int cnt=0;
                while(1){
                    if(j==-1)
                        j=n-1;
                    sum+=code[j];
                    cnt++;
                    if(cnt==k)
                        break;
                    j--;
                }
                vec[i]=sum;
                k=(-1)*k;
            }
        }
        return vec;
    }
};