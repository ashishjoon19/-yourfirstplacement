class Solution {
private:
    int MOD=1000000000+7;
public:
    int lengthAfterTransformations(string s, int t) {
        int res=0;
        vector<int>m(26,0);
        for(auto it:s)
            m[it-'a']++;
        
        while(t--){
            vector<int>m2(26,0);
            for(int i=0;i<26;i++){
                if(i==25){
                    m2[0]=(m2[0]+m[i])%MOD;
                    m2[1]=(m2[1]+m[i])%MOD;
                }
                else
                    m2[i+1]=(m2[i+1]+m[i])%MOD;
            }
            m=m2;
        }
        for(auto it:m){
            res=(res+it)%MOD;
        }
        return res;
    }
};