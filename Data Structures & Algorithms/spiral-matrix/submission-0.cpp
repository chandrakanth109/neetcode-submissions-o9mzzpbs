class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0, top=0;
        int bottom=matrix.size()-1;
        int right=matrix[0].size()-1;

        vector<int> ans;

        while(top <= bottom && left <= right) {
            for(int j=left;j<=right;j++){
                ans.push_back(matrix[top][j]);
            }
            top++;

            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;

            if(top <= bottom) {
                for(int j=right;j>=left;j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if(left <= right) {
                for(int j=bottom;j>=top;j--){
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }
        } 
        return ans;
    }
};
