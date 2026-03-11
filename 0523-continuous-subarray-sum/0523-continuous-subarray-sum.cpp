class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        mpp[0] = -1;
        int runningSum = 0;

        for(int i = 0; i < nums.size() ; i++){
            runningSum += nums[i];
            int rem = runningSum % k;
            if(rem < 0) rem += k;
            if(mpp.find(rem)!= mpp.end()){
                if(i - mpp[rem] >= 2){
                    return true;
                }
            }else{
                mpp[rem] = i;
            }
        }
        return false;
    }
};