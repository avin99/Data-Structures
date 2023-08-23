class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>mp;
        unordered_set<int>set;
        for(int num : arr)mp[num]++;
        for(auto val : mp){
            set.insert(val.second);
        }
        return mp.size() == set.size();
    }
};