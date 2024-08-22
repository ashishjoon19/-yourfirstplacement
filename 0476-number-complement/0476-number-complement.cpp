class Solution {
public:
    int findComplement(int num) {
        vector<int>v;
        while(num>0){
            int rem=num%2;
            v.push_back(rem);
            num/=2;
        }
        int n=v.size();
        int res=0;
        long long mul=1;
        for(int i=0;i<n;i++){
            res+=mul*abs(v[i]-1);
            mul*=2;
        }
        return res;
    }
};