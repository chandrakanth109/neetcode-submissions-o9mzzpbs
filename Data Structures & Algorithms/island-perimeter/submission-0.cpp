class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();

        int perimeter=0;

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) {
                if(grid[i][j]==1) {

                    for(int d=0;d<4;d++){
                        int newX=i+dx[d];
                        int newY=j+dy[d];

                        if(newX < 0 || newY < 0 || newX >= row || newY >= col || grid[newX][newY]==0){
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};