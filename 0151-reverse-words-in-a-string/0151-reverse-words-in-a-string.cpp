class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string tmp;
        stringstream ss(s);
        while(ss >> tmp){
            words.push_back(tmp);
        }
        string result = "";
        for(int i = 0 ; i < words.size() ; i++){
            if(i == 0)
            result = words[i];
            else
            result = words[i]+ " " + result;
        }
        return result;
    }
};