class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int , int> mp;
        for(auto ele: nums){
            mp[ele]++;
        }
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.find(k-nums[i]) != mp.end()){
                if(k - nums[i] == nums[i]){
                    if(mp[nums[i]] < 2)continue;
                    mp[nums[i]]-=2;
                    if(mp[nums[i]] <= 0)mp.erase(nums[i]);
                    cnt++;
                }else{
                    if(mp[nums[i]] < 1 or mp[k - nums[i]] < 1)continue;
                    mp[k-nums[i]]--;
                    mp[nums[i]]--;
                    if(mp[k - nums[i]] <= 0)mp.erase(k - nums[i]);
                    if(mp[nums[i]] <= 0)mp.erase(nums[i]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};