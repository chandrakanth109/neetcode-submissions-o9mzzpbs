class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;

        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }

        for(auto i:mp){
            pq.push({i.second,i.first});
        }

        string ans="";

        while(pq.size() > 1) {
            auto first=pq.top();
            pq.pop();

            auto second=pq.top();
            pq.pop();

            ans+=first.second;
            ans+=second.second;

            first.first--;
            second.first--;

            if(first.first > 0){
                pq.push(first);
            }

            if(second.first > 0){
                pq.push(second);
            }
        }

        if(!pq.empty()) {
            if(pq.top().first > 1){
                return "";
            }
            ans+=pq.top().second;
        }

        return ans;
    }
};