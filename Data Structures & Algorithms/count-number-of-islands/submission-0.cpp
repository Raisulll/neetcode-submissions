class Solution {
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0, r=grid.size(), c=grid[0].size();
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    bool check(vector<vector<char>>&grid, int r, int c){
        int i=grid.size(),j=grid[0].size();
        if(r>=0 and r<i and c>=0 and c<j) return true;
        return false;
    }
    void bfs(vector<vector<char>>&grid, int r, int c){
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]='0';
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            for(int i=0; i<4; ++i){
                if(check(grid,a+dx[i],b+dy[i]) and grid[a+dx[i]][b+dy[i]]=='1'){
                    q.push({a+dx[i],b+dy[i]});
                    grid[a+dx[i]][b+dy[i]]='0';
                }
            }
        }
    }

};
