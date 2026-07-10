class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //unordered_map<int,list<int>> adjList;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        for(auto i:trust) {
           // adjList[i[0]].push_back(i[1]);
            outdegree[i[0]]++;
            indegree[i[1]]++;
        } 

        vector<int> arr;
        for(int i=1;i<=n;i++) {
            if(indegree[i]==n-1 && outdegree[i]==0){
                return i;
            }
        }

        return -1;
    }
};