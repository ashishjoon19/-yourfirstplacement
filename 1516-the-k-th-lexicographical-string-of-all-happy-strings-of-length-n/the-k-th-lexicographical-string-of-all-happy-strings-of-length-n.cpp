class Solution {
private:
    vector<string>res;
    void find(int idx,string str,int &n){
        if(idx==n){
            res.push_back(str);
            return;
        }
        if(idx==0 || str[idx-1]!='a')
            find(idx+1,str+'a',n);
        if(idx==0 || str[idx-1]!='b')
            find(idx+1,str+'b',n);
        if(idx==0 || str[idx-1]!='c')
            find(idx+1,str+'c',n);
    }
public:
    string getHappyString(int n, int k) {
        find(0,"",n);
        if(res.size() < k)
            return "";
        return res[k-1];
    }
};