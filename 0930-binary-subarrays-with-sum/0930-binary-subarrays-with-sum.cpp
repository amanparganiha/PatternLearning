class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int , int> mpp;
        mpp[0] = 1;
        int prefSum = 0;
        int count = 0;

        for(int it : nums){
            prefSum += it;
            if(mpp.find(prefSum-goal) != mpp.end()){
                count += mpp[prefSum - goal];
            }
            mpp[prefSum]++;
        }
        return count;
    }
};