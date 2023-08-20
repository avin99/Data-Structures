class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixProduct(n,1);
        vector<int>suffixProduct(n,1);
        vector<int>answer(n);
        int val;
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                val = nums[i];
                continue;
            }
            prefixProduct[i] = prefixProduct[i - 1] * val;
            val = nums[i];
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            if(i == n-1){
                val = nums[i];
                continue;
            }
            suffixProduct[i] = suffixProduct[i + 1] * val;
            val = nums[i];
        }
        for(int i = 0 ; i < n ; i++){
            answer[i] = prefixProduct[i] * suffixProduct[i];
        }
        return answer;
    }
};