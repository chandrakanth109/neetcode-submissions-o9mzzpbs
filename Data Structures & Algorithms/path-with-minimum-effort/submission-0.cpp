class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        dist[0][0]=0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        while(!pq.empty()) {
            auto frontNode=pq.top();
            pq.pop();

            int nodeDist=frontNode.first;
            int x=frontNode.second.first;
            int y=frontNode.second.second;

            if(x==n-1 && y==m-1){
                return dist[x][y];
            }

            for(int i=0;i<4;i++) {
                int newX=dx[i]+x;
                int newY=dy[i]+y;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int currDist = abs(heights[x][y] - heights[newX][newY]);
                    int newDist=max(currDist, nodeDist);
                    if(newDist < dist[newX][newY]) {
                        dist[newX][newY] = newDist;
                        pq.push({newDist,{newX,newY}});
                    }
                }
            }
        }

        return -1;
    }
};