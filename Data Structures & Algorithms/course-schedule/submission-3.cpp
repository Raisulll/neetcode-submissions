class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> vis(numCourses, 0);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (adj[i].size() == 0) vis[i] = 2;
        }

        for (int i = 0; i < numCourses; ++i) {
            if(vis[i]==2) continue;
            if(!dfs(prerequisites, adj, vis, i)){
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& pre, unordered_map<int, vector<int>>& adj, vector<int>& vis, int cur ){
        if(vis[cur]==2) return true;
        if(vis[cur]==1) return false;
        vis[cur]=1;
        int course=0;
        for(auto it:adj[cur]){
            if(dfs(pre, adj, vis, it)){
                course++;
            }
        }
        // cout<<"cur "<<cur<<" course "<<course<<" size "<<adj[cur].size()<<endl;
        if(course==adj[cur].size()){
            vis[cur]=2; 
            return true;
        }else{
            return false;
        }
    }
};
