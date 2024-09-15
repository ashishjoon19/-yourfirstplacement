class Solution {
public:
    int findTheLongestSubstring(string s) {
        int maxi=0;
        map<string,int>m;
        m["00000"]=-1;
        vector<int>cnt(5,0);
        int c=0;
        for(auto it:s){
            if(it=='a')
                cnt[0]=(cnt[0]+1)%2;
            if(it=='e')
                cnt[1]=(cnt[1]+1)%2;
            if(it=='i')
                cnt[2]=(cnt[2]+1)%2;
            if(it=='o')
                cnt[3]=(cnt[3]+1)%2;
            if(it=='u')
                cnt[4]=(cnt[4]+1)%2;
            string str="";
            str+=to_string(cnt[0])+to_string(cnt[1])+to_string(cnt[2])+to_string(cnt[3])+to_string(cnt[4]);
            if(m.find(str)!=m.end()){
                maxi=max(maxi,c-m[str]);
            }
            else{
                m[str]=c;
            }
            c++;
        }
        return maxi;
    }
};