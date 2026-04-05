class Solution {
public:

    int atMostK(vector<int> &nums , int k){
        int l = 0;
        int count = 0;
        unordered_map<int , int> freq;

        for(int r = 0; r < nums.size(); r++){
            freq[nums[r]]++;
            if(freq[nums[r]] == 1) k--;

            while(k < 0){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) k++;
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums , k-1);
    }
};