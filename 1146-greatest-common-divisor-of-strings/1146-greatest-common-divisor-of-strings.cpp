class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string maxDivisor = "";
        for(int i = min (str1.size(), str2.size()); i >= 1; i--){
            string base = str1.substr(0,i);
            if( str1.size() % i > 0 || str2.size() % i >0)continue;
            if(finalString(base, str1.size()/i) == str1 && finalString(base, str2.size()/i) == str2){
                maxDivisor = base;
                break;
            }
        }
        return maxDivisor;
    }
    string finalString(string base, int repetition){
        string output = "";
        for(int i = 0 ; i < repetition ; i++){
            output += base;
        }
        return output;
    }
};