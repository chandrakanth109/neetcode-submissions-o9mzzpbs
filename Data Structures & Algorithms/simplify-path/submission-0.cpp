class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string dir="";

        for(int i=0;i<=path.size();i++) {
            if(i==path.size() || path[i]=='/') {
                if(dir=="" || dir=="."){

                }
                else if(dir==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
            
            else {
                st.push(dir);
            }
            dir= "";
        } 
        else {
            dir += path[i];
        }
    }

    vector<string> temp;

    while(!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }

    reverse(temp.begin(),temp.end());

    string ans="";

    for(string s:temp){
        ans+="/" + s;
    }

    return ans.empty() ? "/" : ans;
    }
};