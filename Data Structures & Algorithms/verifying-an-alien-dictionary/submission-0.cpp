class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26,0);

        for(int i=0;i<order.size();i++) {
            rank[order[i]-'a']=i;
        }

        for(int i=0;i<words.size()-1;i++) {
            string s1=words[i];
            string s2=words[i+1];

            int j=0;

            while(j < s1.size() && j < s2.size()) {
                if(s1[j]!=s2[j]){
                    if(rank[s1[j]-'a'] > rank[s2[j]-'a']){
                        return false;
                    }
                    break;
                }
                j++;
            }

            if (j==s2.size() && s1.size() > s2.size()){
                return false;
            } 
        }

        return true;
    }
};