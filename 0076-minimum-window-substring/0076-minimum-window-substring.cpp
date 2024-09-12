class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        map<char,int>map_t_str;
        for(auto it:t)
            map_t_str[it]++;
        
        string res="";
        if(t.length()==1){
            for(auto it:s){
                if(it==t[0]){
                    return res+it;
                }
            }
            return "";
        }
        
        int mini=INT_MAX;
        map<char,int>comp;
        map<char,int>real;
        int i=0,j=0;
        while(j<n){
            if(map_t_str.find(s[j])!=map_t_str.end()){
                real[s[j]]++;
                if(comp[s[j]] < map_t_str[s[j]])
                    comp[s[j]]++;
                if(comp==map_t_str){
                    while(i<=j){
                        if(map_t_str.find(s[i])!=map_t_str.end()){
                            if(real[s[i]] == comp[s[i]])
                                break;
                            real[s[i]]--;
                        }
                        i++;
                    }
                    // cout<<endl<<"j-i+1 = "<<j-i+1<<s.substr(i,j-i+1)<<endl;
                    if(j-i+1 < mini){
                        mini=j-i+1;
                        res=s.substr(i,j-i+1);
                        // cout<<res<<" ";
                    }
                    while(i <= j){
                        if(map_t_str.find(s[i])!=map_t_str.end()){
                            real[s[i]]--;
                            if(real[s[i]] < comp[s[i]]){
                                comp[s[i]]--;
                                i++;
                                break;
                            }
                        }
                        i++;
                    }
                    while(i<=j){
                        if(map_t_str.find(s[i])!=map_t_str.end())
                            break;
                        i++;
                    }
                }
            }
            j++;
        }

        return res;
    }
};