class RecentCounter {
public:
vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        auto it = lower_bound(v.begin(), v.end(), t - 3000);
        return v.size() - (it - v.begin()); 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */