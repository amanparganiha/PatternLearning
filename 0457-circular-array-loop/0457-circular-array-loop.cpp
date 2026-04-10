class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
      int n = nums.size();

      auto nextIndex = [&](int i){
        return ((i+ nums[i]) % n + n) % n;
      };

      for(int i = 0; i < n; i++){
        if(nums[i] == 0) continue;

        int slow = i, fast = i;
        bool forward = nums[i] > 0;

        while(true){
            int nextSlow = nextIndex(slow);
            if((nums[nextSlow] > 0) != forward) break;

            int nextFast = nextIndex(fast);
            if((nums[nextFast] > 0) != forward) break;

            nextFast = nextIndex(nextFast);
            if((nums[nextFast] > 0) != forward) break;

            slow = nextSlow;
            fast = nextFast;

            if(slow == fast){
                if(slow == nextIndex(slow)) break;
                return true;
            }
        }

        int j = i;
        while(nums[j] != 0 && (nums[j] > 0) == forward){
            int next = nextIndex(j);
            nums[j] = 0;
            j = next;
        }
      }
      return false;
    }
};