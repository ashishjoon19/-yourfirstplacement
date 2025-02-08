class NumberContainers {
private:
    map<int,int>ind;
    map<int,set<int>>m;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ind.find(index)!=ind.end()){
            int num=ind[index];
            m[num].erase(index);
        }
        ind[index]=number;
        m[number].insert(index);
    }
    
    int find(int number) {
        if(m.find(number)!=m.end()){
            if(m[number].empty())
                return -1;
            else
                return *m[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */