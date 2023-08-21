class Solution {
public:
    int minPartitions(string n) {
        int ans = INT_MIN;
        for(auto ele:n){
            ans = max(ans, ele - '0');
        }
        return ans;
    }
};