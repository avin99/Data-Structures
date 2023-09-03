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
int maxPath = 0;
    int longestZigZag(TreeNode* root) { 
        helper(root, false, 0);
        helper(root, true, 0);
        return maxPath;
    }
    void helper(TreeNode* node, bool goLeft, int steps){
        if(!node)return;
        maxPath = max(maxPath, steps);
        if(goLeft){
           helper(node -> left, false, ++steps);
           helper(node ->right, true, 1);
        }else{
            helper(node -> right, true, ++steps);
           helper(node ->left, false, 1);
        }
    }
};