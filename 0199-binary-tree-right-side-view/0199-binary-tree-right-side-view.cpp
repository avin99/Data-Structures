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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*> intQueue;
        intQueue.push(root);
        while(!intQueue.empty()){
            for(int i = intQueue.size() ; i > 0 ; i--){
                TreeNode *node = intQueue.front();
                intQueue.pop();
                if(i == 1)ans.push_back(node -> val);
                if(node -> left)intQueue.push(node -> left);
                if(node ->right)intQueue.push(node -> right);
            }
        }
        return ans;
    }
};