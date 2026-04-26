class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int it : asteroids){

            bool destroyed = false;

            while(!st.empty() && st.back() > 0 && it < 0){
                
                if(abs(st.back()) < abs(it)){
                    st.pop_back();
                }else if(abs(st.back()) == abs(it)){
                    st.pop_back();
                    destroyed = true;
                    break;
                }else{
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed)
                st.push_back(it);
        }
        return st;
    }
};