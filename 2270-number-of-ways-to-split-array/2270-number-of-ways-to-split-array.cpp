class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int long long totalSum = 0;
        for(int it : nums) totalSum += it;

        int long long prefSum = 0;
        int count = 0;
        for(int i = 0; i < nums.size() -1 ; i++){
            prefSum += nums[i];
            if(prefSum >= totalSum - prefSum){
                count++;
            }
        }
        return count;
    }
};