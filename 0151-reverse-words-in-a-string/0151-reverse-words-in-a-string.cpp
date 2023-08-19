class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int n = s.size();
        for (int i = n - 1 ; i >= 0 ; i--){
            int k = i;
            if(s[i] == ' ')continue;
            while(i >= 0 && s[i] != ' ')i--;
            result += s.substr(i + 1, k - i) + ' ';
        }
        if(result.back() == ' ')result.pop_back();
        return result;
    }
};