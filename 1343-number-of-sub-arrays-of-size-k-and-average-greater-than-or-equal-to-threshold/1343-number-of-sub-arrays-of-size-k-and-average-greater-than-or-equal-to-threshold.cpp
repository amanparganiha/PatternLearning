class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        vector<int> prefSum(n);
        prefSum[0] = arr[0];
        for(int i = 1; i < n ; i++){
            prefSum[i] = prefSum[i-1] + arr[i];
        }

        int target = k * threshold;
        int count = 0;
        for(int i = 0 ; i + k - 1 < n ; i++){
            int sum;
            if(i == 0){
                sum = prefSum[i+k-1];
            }else{
                sum = prefSum[i+k-1] - prefSum[i-1];
            }

            if(sum >= target){
                count++;
            }
        }
        return count;
    }
};