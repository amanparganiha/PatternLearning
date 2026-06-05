class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int currentMax = INT_MIN;

        //pushing first elment of every list
        for(int i = 0 ; i < k ; i++){
            pq.push({nums[i][0] , i , 0});
            currentMax = max(currentMax , nums[i][0]);
        }

        int start = 0;
        int end = INT_MAX;

        while(pq.size() == k){

            auto cur = pq.top();
            pq.pop();

            int minVal = cur[0];
            int row = cur[1];
            int col = cur[2];

            //updating best range
            if(currentMax - minVal < end - start){
                start = minVal;
                end = currentMax;
            }

            //Moveing to next element in same list
            if(col + 1 < nums[row].size()){
                int nextVal = nums[row][col+1];
                pq.push({nextVal , row , col + 1});
                currentMax = max(currentMax , nextVal);
            }else{
                break;
            }

        }

        return {start , end};
    }
};