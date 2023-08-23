class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int>heights(matrix[0].size(),0);
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '0')heights[j] = 0;
                else heights[j]++;
            }
            maxArea = max(maxArea , largestRectangleArea(heights));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftIndex(n);
        vector<int>rightIndex(n);
        rightIndex[n-1]=n;
        leftIndex[0]=-1;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()])st.pop();
            if(st.empty()){
                rightIndex[i]=n;
            }else{
                rightIndex[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()])st.pop();
            if(st.empty()){
                leftIndex[i]=-1;
            }else{
                leftIndex[i]=st.top();
            }
            st.push(i);
        }
        
        int maxArea=0;
        for(int i=0;i<n;i++){
            int lh=leftIndex[i];
            int rh=rightIndex[i];
            int area=heights[i]*(rh-lh-1);
            if(area>=maxArea)maxArea=area;
        }
        return maxArea;
    }
};