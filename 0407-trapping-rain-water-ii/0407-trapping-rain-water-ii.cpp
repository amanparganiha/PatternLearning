class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if(m < 3 || n < 3)
            return 0;
        
        vector<vector<bool>> visited(m , vector<bool> (n , false));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        //pushing all boundary cells
        for(int i = 0 ; i < m; i++){
            pq.push({heightMap[i][0] , i , 0});
            pq.push({heightMap[i][n-1] , i , n-1});

            visited[i][0] = true;
            visited[i][n-1] = true;
        }

        for(int j = 1; j < n -1; j++){
            pq.push({heightMap[0][j] , 0 , j});
            pq.push({heightMap[m-1][j], m - 1 , j});

            visited[0][j] = true;
            visited[m-1][j] = true;
        }

        int water = 0;

        vector<pair<int , int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int height = cur[0];
            int row = cur[1];
            int col = cur[2];

            for(auto &[dr, dc] : dir){

                int nr = row + dr;
                int nc = col + dc;

                if(nr < 0 || nr >= m ||
                   nc < 0 || nc >= n ||
                   visited[nr][nc])
                   continue;

                visited[nr][nc] = true;

                water += max(0 , height - heightMap[nr][nc]);

                pq.push({
                    max(height , heightMap[nr][nc]),
                    nr,
                    nc
                });
            }
        }

        return water;
    }
};