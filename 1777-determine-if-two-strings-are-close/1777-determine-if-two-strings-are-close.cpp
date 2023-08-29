class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0), w2(26,0), w3(26,0), w4(26,0);
        for(auto ch : word1){
            w1[ch - 'a']++;
            w2[ch - 'a'] = 1;
        }
        for(auto ch : word2){
            w3[ch - 'a']++;
            w4[ch - 'a'] = 1;
        }
        sort(w1.begin(), w1.end());
        sort(w3.begin(), w3.end());
        return w1 == w3 && w2 == w4;
    }
};