class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        mpp[0] = 1;

        int curr_sum = 0;
        int count = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            curr_sum += nums[i];
            int remove = curr_sum - k;
            if(mpp.find(remove) != mpp.end()){
                count += mpp[remove];
            }
            mpp[curr_sum]++;
        }
        return count;
    }
};