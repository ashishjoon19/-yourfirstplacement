class Solution {
private:
    static bool comp(string a,string b){
        return a.length()>b.length();
    }
public:
    int maximumLength(string s) {
        int n=s.length();
        vector<string>vec;
        for(int i=0;i<n;i++){
            string temp="";
            temp+=s[i];
            vec.push_back(temp);
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    temp+=s[i];
                    vec.push_back(temp);
                }
                else
                    break;
            }
        }
        sort(vec.begin(),vec.end(),comp);
        int m=vec.size();
        map<string,int>mapi;
        for(int i=0;i<m;i++){
            mapi[vec[i]]++;
        }
        int res=-1;
        for(auto it:mapi){
            if(it.second>2){
                int len=(it.first).length();
                if(res < len)
                    res=len;
            }
        }
        return res;
    }
};