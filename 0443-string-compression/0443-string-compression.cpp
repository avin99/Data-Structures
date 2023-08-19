class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, n = chars.size() , k = 0 , cnt = 1;
        while(i < n){
            char current = chars[i];
            cnt = 1;
            while ( i + 1 < n && chars[i] == chars[i + 1]){
                cnt++;
                i++;
            }
            chars[k++] = current;
            if(cnt > 1){
                string countVal = to_string(cnt);
                int j = 0;
                while(j < countVal.size()){
                    chars[k++] = countVal[j++];
                }
            }
            i++;
        }
        
        return k;
    }
};