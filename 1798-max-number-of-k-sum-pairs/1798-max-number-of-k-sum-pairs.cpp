class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int , int> mp;
        for(auto ele: nums){
            mp[ele]++;
        }
        int cnt = 0;
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            int val = it->first;
            int freq = it->second;
            if(val == k - val){
                cnt += freq / 2;
            }else{
                int secondVal = k - val;
                if(mp.find(secondVal) == mp.end())continue;
                int mn = min(freq , mp[secondVal]);
                cnt += mn;
                mp[val] -= mn;
                mp[secondVal] -= mn;
            }
        }
        return cnt;
    }
};