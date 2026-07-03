class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> countStack;

        string curr="";
        int num=0;

        for(char ch:s) {
            if(isdigit(ch)) {
                num=num*10+(ch-'0');
            } 
            else if(ch=='[') {
                countStack.push(num);
                stringStack.push(curr);

                curr="";
                num=0;
            } 
            else if(ch==']'){
                int times=countStack.top();
                countStack.pop();

                string prev=stringStack.top();
                stringStack.pop();

                string temp="";
                while(times--){
                    temp+=curr;
                }

                curr=prev+temp;
            } 
            else {
                curr+=ch;
            }
        }

        return curr;
    }
};