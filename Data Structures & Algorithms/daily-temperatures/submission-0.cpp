class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n=temp.size();
        vector<int> ans(n,0);

        for(int i=temp.size()-1;i>=0;i--) {
            int currTemp=temp[i];

            while(!st.empty() && temp[st.top()] <= currTemp){
                st.pop();
            }

             if(st.empty()){
                ans[i]=0;
            } else {
                ans[i]=st.top()-i;
            }

            st.push(i);
            
        }

        return ans;
    }
};
