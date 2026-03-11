class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        int sum = 0;
        int maxLen = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum += (nums[i] == 1) ? 1 : -1;
            if(mpp.find(sum) != mpp.end()){
                maxLen = max(maxLen , i - mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
        return maxLen;
    }
};