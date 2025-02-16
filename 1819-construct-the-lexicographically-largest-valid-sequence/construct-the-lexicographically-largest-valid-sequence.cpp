class Solution {
private:
    vector<int>res;
    int ttl;
    int n;
    void find(vector<int>vis,int &flag,int ind){
        if(flag==n)    return;
        if(ind <ttl && res[ind]!=-1)    find(vis,flag,ind+1);
        else{
            for(int i=n;i>=1;i--){
                if(!vis[i]){
                    if(i==1 && res[ind]==-1){
                        res[ind]=1;
                        vis[i]=1;
                        flag++;
                        find(vis,flag,ind+1);
                        if(flag==n){
                            return;
                        }
                        flag--;
                        vis[i]=0;
                        res[ind]=-1;
                    }
                    else if(ind+i < ttl && res[ind]==-1 && res[ind+i]==-1){
                        res[ind]=i,res[i+ind]=i;
                        vis[i]=1;
                        flag++;
                        find(vis,flag,ind+1);
                        if(flag==n)
                            return;
                        flag--;
                        vis[i]=0;
                        res[ind]=-1,res[i+ind]=-1;
                    }
                }
            }
        }
    }
public:
    vector<int> constructDistancedSequence(int num) {
        ttl=1+(num-1)*2;
        res.resize(ttl,-1);
        vector<int>vis(num+1,0);
        n=num;
        int flag=0;
        find(vis,flag,0);
        return res;
    }
};