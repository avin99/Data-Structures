class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++){
            long need = (success + spells[i] - 1)/spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans[i] = potions.end() - it;
        }
        return ans;
    }
};