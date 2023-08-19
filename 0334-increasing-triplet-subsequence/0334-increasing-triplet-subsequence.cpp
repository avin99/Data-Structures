class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        int maxVal = INT_MIN;
        for(int i = n - 1; i >= 0; i--){
            if(i == n-1){
                suffix[i] = INT_MIN;
                maxVal = max(maxVal, nums[i]);
                continue;
            }
            suffix[i] = maxVal;
            maxVal = max(maxVal, nums[i]);
        }
        int minVal = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                minVal = min(minVal, nums[i]);
                prefix[i] = INT_MAX;
                continue;
            }
            prefix[i] = minVal;
            minVal = min(minVal, nums[i]);
        }

        for(int i = 0 ;i < n; i++){
            if(nums[i] > prefix[i] && nums[i] < suffix[i])return true;
        }

        return false;
    }
};