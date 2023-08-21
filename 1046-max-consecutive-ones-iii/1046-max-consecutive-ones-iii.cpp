class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0;
        int start = 0;
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                zeros++;
            }
            while(zeros > k){
                if(nums[start] == 0){
                    zeros--;
                }
                start++;
            }
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};