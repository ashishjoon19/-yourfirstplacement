class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length();
        int j=0,left=0,right=0;
        for(int i=0;i<n;i++){
            if(target[i]=='L'){
                left++;
                j=max(j,i);
                while(j<n){
                    if(start[j]=='L'){
                        break;
                    }
                    else if(start[j]=='R'){
                        return false;
                    }
                    j++;
                }
                if(j>=n)
                    return false;
                j++;
            }
            else if(target[i]=='R')
                right++;
        }
        j=0;
        for(int i=0;i<n;i++){
            if(start[i]=='R'){
                right--;
                j=max(j,i);
                while(j<n){
                    if(target[j]=='R'){
                        break;
                    }
                    else if(target[j]=='L'){
                        return false;
                    }
                    j++;
                }
                if(j>=n)
                    return false;
                j++;
            }
            else if(start[i]=='L')
                left--;
        }
        if(left==0 && right==0)
            return true;
        else return false;
    }
};