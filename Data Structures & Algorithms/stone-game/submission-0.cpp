class Solution {
public:

    int solve(vector<int>& piles,int i,int j) {
        if(i==j){
            return piles[i];
        }

        int takeLeft=solve(piles,i+1,j);
        int takeRight=solve(piles,i,j+1);

        return max(takeLeft,takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        return solve(piles,0,0) > 0;
    }
};