class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> need , window;

        for(char it : t) need[it]++;

        int l = 0 , r = 0;
        int formed = 0;
        int required = need.size();

        int minLen = INT_MAX , start = 0;

        while(r < s.size()){
            char c = s[r];
            window[c]++;

            if(need.count(c) && window[c] == need[c])
               formed++;

            while(formed == required){
                if(r -l +1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }
                char ch = s[l];
                window[ch]--;

                if(need.count(ch) && window[ch] < need[ch])
                   formed--;
                
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start , minLen);
    }
};