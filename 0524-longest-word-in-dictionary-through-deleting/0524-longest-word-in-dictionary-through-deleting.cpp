class Solution {
public:
    bool isSubsequence(string s , string word){
        int i = 0;
        int j = 0;
        while(i < s.size() && j < word.size() ){
            if(s[i] == word[j]) j++;
            i++;
        }
        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(string word : dictionary){

            if(isSubsequence(s, word)){
                if(word.length() > ans.length() ||
                   (word.length() == ans.length() && word < ans)){
                    ans = word;
                }
            }
        }
        return ans;
    }
};