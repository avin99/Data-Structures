class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int roomKey = q.front();
            vis[roomKey] = 1;
            q.pop();
            for(auto ele : rooms[roomKey]){
                if(!vis[ele])
                q.push(ele);
            }
        }
        for(auto val : vis){
            if(val != 1)return false;
        }
        return true;
        
    }
};