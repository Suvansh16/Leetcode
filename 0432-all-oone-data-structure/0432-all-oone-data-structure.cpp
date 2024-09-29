class AllOne {
public:
set<pair<int,string>>temp;
unordered_map<string,int>map;
    AllOne() {
        temp.clear();
    }
    
    void inc(string key) {
        int n=map[key];
        map[key]++;
        temp.erase({n,key});
        temp.insert({n+1,key});
    }
    
    void dec(string key) {
        int n=map[key];
        map[key]--;
        temp.erase({n,key});
        if(map[key]>0)temp.insert({n-1,key});
        else
        map.erase(key);
    }
    
    string getMaxKey() {
        if(!temp.empty())
        {
            return temp.rbegin()->second;
        }
        return "";
    }
    
    string getMinKey() {
        if(!temp.empty())
        return temp.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */