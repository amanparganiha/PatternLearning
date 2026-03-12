class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0 ;
        for(int top = 0 ; top < r ; top++){
            vector<int> colSum(c , 0);

            for(int bottom = top ; bottom < r ; bottom++){

                for(int i = 0; i < c; i++){
                    colSum[i] += matrix[bottom][i];
                }
                   
                unordered_map<int , int> prefix;
                prefix[0] = 1;
                int currSum = 0;

                for(int it : colSum){
                    currSum += it;

                    if(prefix.count(currSum - target)){
                        ans += prefix[currSum - target];
                    }
                    prefix[currSum]++;
                }
            }
        }
        return ans;
    }
};