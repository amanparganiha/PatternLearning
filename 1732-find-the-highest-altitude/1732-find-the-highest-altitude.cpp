class Solution {
public:
    vector<int> alti;
    int largestAltitude(vector<int>& gain) {
      int n = gain.size();
      alti.resize(n+1);
      alti[0]= 0;
      for(int i = 1; i <= n ; i++){
        alti[i] = alti[i-1] + gain[i-1];
      }
      return *max_element(alti.begin() , alti.end()); 
    }
};