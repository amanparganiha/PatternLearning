class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        mpp[0] = 1;
        int sum = 0;
        int count = 0;

        for(int it : nums){
            sum += it;
            int rem = ((sum % k) + k) % k;

            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }
            mpp[rem]++;
        }
        return count;
    }
};