class MyCalendar {
public:
    MyCalendar() {
        
    }
    set<pair<int,int>>s;
    bool book(int start, int end) {
        for(auto it : s){
            if(max(it.first, start) < min(it.second, end)) 
                return false;
        }
        s.insert({start, end});
        return true;
    }
};