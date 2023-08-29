class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<string>rows;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            string row = "";
            for(int j = 0 ; j < m ; j++){
                row += to_string(grid[i][j]) + '#';
            }
            rows.push_back(row);
        }
        for(int i = 0 ; i < n ; i++){
            cout<<rows[i]<<" ";
        }
        cout<<endl;
        for(int i = 0 ; i < m ; i++){
            string row = "";
            for(int j = 0 ; j < n ; j++){
                row += to_string(grid[j][i]) + '#';
            }
            cout<<row<< " ";
            cnt += count(rows.begin(), rows.end(), row);
                
        }
        return cnt;
    }
};