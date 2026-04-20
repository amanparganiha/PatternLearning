class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        vector<bool> visited(26 , false);

        for(int i = 0; i < s.size() ; i++)
            last[s[i] - 'a'] = i;

        stack<char> st;

        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];

            if(visited[c - 'a']) continue;

            while(!st.empty() && st.top() > c && last[st.top() - 'a'] > i){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            visited[c - 'a'] = true;
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin() , res.end());
        return res;
    }
};