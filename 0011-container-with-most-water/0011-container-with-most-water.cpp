class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0 ; 
        int j = n - 1;
        int ans = INT_MIN;
        while(i < j){
            int mn = min(height[i] , height[j]);
            ans = max(ans , (j - i)*mn);
            if(height[i] < height[j])i++;
            else if(height[i] > height[j])j--;
            else{
                i++;j--;
            }
        }
        return ans;
    }
};