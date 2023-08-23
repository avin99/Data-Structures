class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int prev;
        for(int i = 0 ; i < n ; i++ ){
            if(i == 0){
                prev = nums[i];
            }else{
                prefix[i] = prefix[i-1] + prev;
                prev = nums[i];
            }
        }
        for(int i = n - 1; i >= 0 ; i--){
            if(i == n - 1){
                prev = nums[i];
            }else{
                suffix[i] = suffix[i + 1] + prev;
                prev = nums[i];
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(prefix[i] == suffix[i])return i;
        }
        return -1;
    }
};