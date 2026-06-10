class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;

        long long fuel = startFuel;
        int i = 0;
        int n = stations.size();

        int stops = 0;

        while(fuel < target){
            while(i < n && stations[i][0] <= fuel){
                pq.push(stations[i][1]);
                i++;
            }

            if(pq.empty())
               return -1;
            
            fuel += pq.top();
            pq.pop();

            stops++;
        }

        return stops;
    }
};