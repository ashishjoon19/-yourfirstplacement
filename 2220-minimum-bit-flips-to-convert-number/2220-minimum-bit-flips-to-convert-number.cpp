class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        while(start!=goal){
            int a=start&1;
            int b=goal&1;
            start=start>>1;
            goal=goal>>1;
            if(a!=b)
                cnt++;
        }
        return cnt;
    }
};