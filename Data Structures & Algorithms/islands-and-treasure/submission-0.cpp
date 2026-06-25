int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==0){
                    bfs(grid,i,j);
                }
            }
        }
    }
    void bfs(vector<vector<int>>&grid, int r, int c){
        queue<pair<int,int>>q; 
        q.push({r,c});
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            for(int i=0; i<4; ++i){
                int nx=a+dx[i];
                int ny=b+dy[i];
                if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size()){
                    if(grid[nx][ny]!=0 and grid[nx][ny]!=-1){
                        if(grid[nx][ny]>grid[a][b]+1){
                            q.push({nx,ny});
                            grid[nx][ny]=grid[a][b]+1;
                        }
                    }
                }
            }
        }
    }
};
