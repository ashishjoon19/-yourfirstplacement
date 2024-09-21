class Solution {
public:
    vector<int>res;
    void find(int i,int n){
        for(int k=0;k<=9;k++){
            if(i+k > n || ((i+k)%10 == 0 && k != 0))
                return;
            res.push_back(i+k);
            if((i+k)*10 <= n){
                find((i+k)*10,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        find(1,n);
        return res;
    }
};