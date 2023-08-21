class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < k ; i++){
            sum += nums[i];
        }
        int i = 0, j = k;
        int ans = sum;
        while(j < n){
            sum -= nums[i];
            sum += nums[j];
            i++;j++;
            ans = max(ans, sum);
        }
        return ans/(k*1.0);
    }
};