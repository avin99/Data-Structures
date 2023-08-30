class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>intStack;
        vector<int>answer;
        for(int i = 0 ; i < n ; i++){
            if(intStack.empty() || asteroids[i] > 0){
                intStack.push(asteroids[i]);
            }else{
                while(!intStack.empty() && intStack.top() > 0 && abs(asteroids[i]) > intStack.top()){
                    intStack.pop();
                }
                if(!intStack.empty() && intStack.top() > 0 && intStack.top() == abs(asteroids[i])){
                    intStack.pop();
                }else if(intStack.empty() || intStack.top() < 0){
                    intStack.push(asteroids[i]);
                }
            }
        }
    
        while(!intStack.empty()){
            answer.push_back(intStack.top());
            intStack.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};