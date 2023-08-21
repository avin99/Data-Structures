class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0 , ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(i < k){
                sum += nums[i];
            }else{
                ans = max(ans , sum);
                sum += nums[i] - nums[i - k];
            }
        }
        ans = max(ans, sum);
        return ans/k;
    }
};