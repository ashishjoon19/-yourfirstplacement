class Solution {
public:
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        int mod=1e9+7;
        ll axorx=0;
        ll bxorx=0;

        for(int i=49;i>n-1;i--){
            int a_ith_bit=a>>i & 1;
            int b_ith_bit=b>>i & 1;
            if(a_ith_bit){
                axorx=axorx ^ 1ll<<i;
            }
            if(b_ith_bit){
                bxorx=bxorx ^ 1ll<<i;
            }
        }
        for(int i=n-1;i>=0;i--){
            int a_ith_bit=a>>i & 1;
            int b_ith_bit=b>>i & 1;
            if(a_ith_bit==b_ith_bit){
                axorx=axorx ^ 1ll<<i;
                bxorx=bxorx ^ 1ll<<i;
                continue;
            }
            
            if(axorx > bxorx)
                bxorx=bxorx ^ 1ll<<i;
            else
                axorx=axorx ^ 1ll<<i;
        }
        return ((axorx%mod)*(bxorx%mod))%mod;
    }
};