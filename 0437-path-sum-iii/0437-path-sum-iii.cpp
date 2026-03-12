/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<long long , int> prefSum;
    int count = 0;
    void dfs(TreeNode *node , long long currSum , int target){
        if(!node) return;

        currSum += node->val ;
        if(prefSum.count(currSum - target)){
            count += prefSum[currSum - target];
        }

        prefSum[currSum]++;

        dfs(node->left , currSum , target);
        dfs(node->right , currSum , target);

        prefSum[currSum]--;
        }

    int pathSum(TreeNode* root, int targetSum) {
            prefSum[0] = 1;
            dfs(root , 0 , targetSum);
            return count;
    }
};