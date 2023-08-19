class Solution {
public:
    string reverseVowels(string s) {
        int i = 0 , j = s.size() - 1;

        while(i < j){
            if(tolower(s[i]) == 'a' or tolower(s[i]) == 'e' or tolower(s[i]) == 'i' or tolower(s[i]) == 'o' or tolower(s[i]) == 'u'){
                if(tolower(s[j]) == 'a' or tolower(s[j]) == 'e' or tolower(s[j]) == 'i' or tolower(s[j]) == 'o' or tolower(s[j]) == 'u'){
                swap(s[i],s[j]);i++;j--;continue;
                }
                j--;
            }else if (tolower(s[j]) == 'a' or tolower(s[j]) == 'e' or tolower(s[j]) == 'i' or tolower(s[j]) == 'o' or tolower(s[j]) == 'u'){
                if(tolower(s[i]) == 'a' or tolower(s[i]) == 'e' or tolower(s[i]) == 'i' or tolower(s[i]) == 'o' or tolower(s[i]) == 'u'){
                    swap(s[i],s[j]);i++;j--;continue;
                }
                i++;
            }else {
                i++;j--;
            }
        }
        return s;
    }
};