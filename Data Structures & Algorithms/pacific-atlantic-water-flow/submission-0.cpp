class Solution {
public:

    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited) {

        visited[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        for(int d=0;d<4;d++) {
            int newX=dx[d]+i;
            int newY=dy[d]+j;

            if(newX >=0 && newY >=0 && newX < n && newY < m && !visited[newX][newY] && grid[newX][newY] >= grid[i][j]) {
                dfs(grid,newX,newY,visited);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();

        vector<vector<bool>>pacific (row,vector<bool>(col,false));
        vector<vector<bool>>atlantic (row,vector<bool>(col,false));

        for(int i=0;i<col;i++) {
            dfs(heights,0,i,pacific);
        }

        for(int i=0;i<row;i++) {
            dfs(heights,i,0,pacific);
        }

        for(int i=0;i<col;i++) {
            dfs(heights,row-1,i,atlantic);
        }

        for(int i=0;i<row;i++) {
            dfs(heights,i,col-1,atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) {
                if(pacific[i][j]==true && atlantic[i][j]==true) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
