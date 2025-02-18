class Solution {
    char base;
    int n;
private:
    void find(string pattern,int idx,vector<int>vis,string &nums,int &flag){
        if(idx==n || flag==1){
            flag=1;
            return;
        }
            
        if(pattern[idx]=='I'){
            for(int i=nums[idx]-'0'+1;i<=9;i++){
                if(!vis[i]){
                    nums[idx+1]=i+base;
                    vis[i]=1;
                    find(pattern,idx+1,vis,nums,flag);
                    vis[i]=0;
                    if(flag)
                        return;
                    nums[idx+1]='-1';
                }
            }
        }
        else{
            for(int i=nums[idx]-'0'-1;i>=1;i--){
                if(!vis[i]){
                    nums[idx+1]=i+base;
                    vis[i]=1;
                    find(pattern,idx+1,vis,nums,flag);
                    if(flag)
                        return;
                    vis[i]=0;
                    nums[idx+1]='-1';
                }
            }
        }
    }
public:
    string smallestNumber(string pattern) {
        n=pattern.length();
        base='0';
        // cout<<base<<endl;
        string nums(n+1,'0');
        // cout<<nums;
        vector<int>vis(n+2,0);
        if(pattern[0]=='I'){
            nums[0]=1+base;
            vis[1]=1;
        }
        else{
            int cnt=0;
            for(auto it:pattern){
                if(it=='D')
                    cnt++;
                else
                    break;
            }
            nums[0]=cnt+1+base;
            vis[cnt+1]=1;
        }
        int flag=0;
        find(pattern,0,vis,nums,flag);
        return nums;
    }
};