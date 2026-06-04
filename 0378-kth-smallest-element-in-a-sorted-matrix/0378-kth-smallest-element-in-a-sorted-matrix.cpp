class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        for(int r = 0 ; r < n; r++){
            pq.push({matrix[r][0] , r , 0});
        }

        int ans = 0;

        while(k--){
            auto cur = pq.top();
            pq.pop();

            int value = cur[0];
            int row = cur[1];
            int col = cur[2];

            ans = value;

            if(col + 1 < n){
                pq.push({matrix[row][col + 1] , row , col + 1});
            }
        }
        return ans;
    }
};