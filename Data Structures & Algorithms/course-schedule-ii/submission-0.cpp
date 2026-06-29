class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int,vector<int>> adj;
        vector<int> vis(numCourses, 0);
        unordered_set<int>st;
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0; i<numCourses; ++i){
            if(adj[i].size()==0){
                vis[i]=2;
                st.insert(i);
                ans.push_back(i);
            }
        }
        for(int i=0; i<numCourses; ++i){
            if(vis[i]==2) continue;
            vector<int>path;
            if(!dfs(prerequisites, adj, vis, path, i)){
                return { };
            }else{
                for(auto it:path){
                    if(!st.count(it)){
                        st.insert(it);
                        ans.push_back(it);
                    }
                }
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& pre, unordered_map<int, vector<int>>& adj,vector<int>& vis, vector<int>& path, int cur ){
        if(vis[cur]==1) return false;
        if(vis[cur]==2){
            path.push_back(cur);
            return true;
        }
        vis[cur]=1;
        int courses=0;
        for(auto it:adj[cur]){
            if(dfs(pre, adj, vis, path, it)){
                courses++;
            }
        }
        if(courses==adj[cur].size()){
            path.push_back(cur);
            vis[cur]=2;
            return true;
        }else{
            return false;
        }
    }
};
