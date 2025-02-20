class Solution {
private:
    map<string,bool>vec;
    set<string>sets;
    bool find(string str,int n){
        if(n==0) return true;
        if(vec.find(str)!=vec.end()) return vec[str];
        string word="";
        bool flag=false;
        for(int i=0;i<n;i++){
            word+=str[i];
            if(sets.find(word)!=sets.end()){
                flag |= find(str.substr(i+1,n),n-i-1);
            }
        }
        vec[str]=flag;
        return flag;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it:wordDict){
            sets.insert(it);
            vec[it]=true;
        }
        return find(s,s.length());
    }
};