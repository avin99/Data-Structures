class Solution {
public:
    string decodeString(string s) {
        stack<char>charStack;
        int n = s.size();
        string answer = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ']'){
                string subString = "";
                while(!charStack.empty() && charStack.top() != '['){
                    subString += charStack.top();
                    charStack.pop();
                }
                cout<<subString<<" ";
                charStack.pop();
                string num = "";
                while(!charStack.empty() && isdigit(charStack.top())){
                    num += charStack.top();
                    charStack.pop();
                }
                reverse(num.begin(), num.end());
                int k = stoi(num);
                cout<<k<<" ";
                reverse(subString.begin(), subString.end());
                string finalString = "";
                for(int j = 0 ; j < k ; j++){
                    finalString += subString;
                }
                for(auto ch : finalString){
                    charStack.push(ch);
                }
            }else{
                charStack.push(s[i]);
            }
        }
        string leftString = "";
        while(!charStack.empty()){
            leftString += charStack.top();
            charStack.pop();
        }
        reverse(leftString.begin(), leftString.end());
        answer += leftString;
        return answer;
    }
};