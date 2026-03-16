class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int l = 0;
        int r = n -1;
        int pos = n -1;

        while(l <= r){
            int lSqr = nums[l]*nums[l];
            int rSqr = nums[r]*nums[r];

            if(lSqr > rSqr){
                result[pos] = lSqr;
                l++;
            }else{
               result[pos] = rSqr;
                r--; 
            }
 
            pos--;
        }

        return result;
    }
};