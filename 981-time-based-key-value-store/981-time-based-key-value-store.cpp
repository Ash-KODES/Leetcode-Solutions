class TimeMap {
public:
    TimeMap() {
        
    }
    map<string,map<int,string>> mp;
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp[key].find(timestamp)==mp[key].end())
        {
            if(mp[key].size()==0||(mp[key].size()!=0&&mp[key].begin()->first>timestamp))
            return "";
            return (--mp[key].lower_bound(timestamp))->second;
        }
        return mp[key][timestamp];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */