class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int>arr;
        arr.push_back(pref[0]);
        for(int i=1;i<n;i++){
            int a=pref[i-1];
            int b=pref[i];
            cout<<"a= "<<a<<" b= "<<b<<endl;
            int x=0,k=0;
            
            while(a!=0 || b!=0){
                int a_last=1&a;
                a=a>>1;
                int b_last=1&b;
                b=b>>1;
                int val=1;
                if(a_last==b_last){
                    val=0;
                }
                x=x|val<<k;
                k++;
            }
            arr.push_back(x);
        }
        return arr;
    }
};