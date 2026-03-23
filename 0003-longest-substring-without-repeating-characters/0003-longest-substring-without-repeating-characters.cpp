class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSt;
        int l = 0 ;
        int res = 0;

        for(int r = 0; r < s.size() ; r++){
            while(charSt.find(s[r]) != charSt.end()){
                charSt.erase(s[l]);
                l++;
            }
            charSt.insert(s[r]);
            res = max(res , r-l+1);
        }
        return res;
    }
};