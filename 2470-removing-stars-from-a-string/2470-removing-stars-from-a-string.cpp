class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto ch : s){
            if(st.empty()){
                st.push(ch);
                continue;
            }
            if(ch == '*' && !st.empty()){st.pop();continue;}
            st.push(ch);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};