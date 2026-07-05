class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int time=-1;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        while(!q.empty()) {
            int size=q.size();

            while(size--) {
                auto [x,y] = q.front();
                q.pop();

                for(int i=0;i<4;i++) {
                    int newX=dx[i]+x;
                    int newY=dy[i]+y;

                    if(newX >= 0 && newX < n && newY >=0 && newY < m && grid[newX][newY]==1){
                        grid[newX][newY]=2;
                        q.push({newX,newY});
                    }
                }
            }
            time++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }

        return time==-1 ? 0 : time;
    }
};
