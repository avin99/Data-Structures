class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int leftSum = 0;
        for(auto ele: nums)sum += ele;
        for(int i = 0 ; i < n ; i++){
            if(leftSum == sum - nums[i])return i;
            sum -= nums[i];
            leftSum += nums[i];
        }
        return -1;
    }
};