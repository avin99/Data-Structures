class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j])adj[i].push_back(j);
            }
        }
        int provinces = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i,adj, vis);
                provinces++;
            }
        }
        return provinces;
    }
    void dfs(int i, vector<int>adj[], vector<int>&vis){
        vis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]) dfs(it ,adj, vis);
        }
    }
};