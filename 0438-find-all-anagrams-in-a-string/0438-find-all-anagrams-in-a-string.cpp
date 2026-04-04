class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.size() , m = p.size();

        if(m > n) return result;

        vector<int> freqP(26,0) , freqS(26, 0);

        for(char it : p){
            freqP[it - 'a']++;
        }

        for(int i = 0; i < m ; i++){
            freqS[s[i] - 'a']++;
        }

        if(freqP == freqS) result.push_back(0);

        for(int i = m ; i < n; i++){
            freqS[s[i] - 'a']++;
            freqS[s[i-m] - 'a']--;

            if(freqP == freqS){
                result.push_back(i-m+1);
            }
        }
        return result;
    }
};