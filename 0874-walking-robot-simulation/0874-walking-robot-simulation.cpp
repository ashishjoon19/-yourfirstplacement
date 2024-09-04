class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x_axis=0,y_axis=0;
        int maxi=0;
        char dir='n';
        map<char,pair<int,int>>to_add;
        to_add['n']={1,0};
        to_add['s']={-1,0};
        to_add['e']={0,1};
        to_add['w']={0,-1};

        map<pair<char,int>,char>getdir;
        getdir[{'n',-1}]='e';
        getdir[{'n',-2}]='w';
        getdir[{'e',-1}]='s';
        getdir[{'e',-2}]='n';
        getdir[{'w',-1}]='n';
        getdir[{'w',-2}]='s';
        getdir[{'s',-1}]='w';
        getdir[{'s',-2}]='e';

        map<pair<int,int>,int>obs;
        for(auto it:obstacles)
            obs[{it[0],it[1]}]=1;

        for(auto k:commands){
            if(k==-1 || k==-2)
                dir=getdir[{dir,k}];
            
            else{
                while(k--){
                    x_axis += to_add[dir].second;
                    y_axis += to_add[dir].first;
                    if(obs.find({x_axis,y_axis})!=obs.end()){
                        x_axis += -(to_add[dir].second);
                        y_axis += -(to_add[dir].first);
                        break;
                    }
                    maxi=max(maxi,x_axis*x_axis+y_axis*y_axis);
                }
            }
        }
        cout<<x_axis<<" "<<y_axis;

        return maxi=max(maxi,x_axis*x_axis+y_axis*y_axis);
    }
};