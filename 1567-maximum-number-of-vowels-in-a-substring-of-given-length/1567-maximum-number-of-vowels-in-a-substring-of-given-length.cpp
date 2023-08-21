class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        int ans = INT_MIN;
        int n = s.size();
        int ind = 0;
        for(int i = 0 ; i < n ; i++){
            if(i < k){
                if(isVowel(s[i]))cnt++;
            }else{
                ans = max(ans, cnt);
                if(isVowel(s[ind]))cnt--;
                if(isVowel(s[i]))cnt++;
                ind++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
    bool isVowel(char c){
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')return true;
        else return false;
    }
};