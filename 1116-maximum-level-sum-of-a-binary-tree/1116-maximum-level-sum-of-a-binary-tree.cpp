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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        int leastLevel;
        int maxSum = INT_MIN;
        while(!q.empty()){
            level++;
            int levelSum = 0;
            for(int i = q.size() ; i > 0 ; i--){
                TreeNode *node = q.front();
                q.pop();
                levelSum += node -> val;
                if(node -> left)q.push(node -> left);
                if(node -> right)q.push(node ->right);
            }
            if(levelSum > maxSum){
                    leastLevel = level;
                    maxSum = levelSum;
                }
        }
        return leastLevel;
    }
};