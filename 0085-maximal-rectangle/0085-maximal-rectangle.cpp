class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int start_i = 0; start_i < n ; start_i++){
            for(int start_j = 0 ; start_j < m ; start_j++){
                if(matrix[start_i][start_j] != '1')continue;
                int minWidth = INT_MAX;
                for(int end_i = start_i ; end_i < n && matrix[end_i][start_j] == '1' ; end_i++){
                    int width = 0;
                    for(int end_j = start_j ; end_j < m && matrix[end_i][end_j] == '1' ; end_j++){
                        width++;
                    }
                    minWidth = min(minWidth, width);
                    ans = max(ans, (end_i - start_i + 1) * minWidth);
                }
            }
        }
        return ans;
    }
};