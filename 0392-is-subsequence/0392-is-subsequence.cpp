class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size()) return false;
        int lastInd = -1;
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = 0 ; j < t.size() ; j++){
                if(t[j] == s[i] && lastInd < j){
                    lastInd = j;break;
                }
                if( j == t.size() - 1)return false;
            }
        }
        return true;
    }
};