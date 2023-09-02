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
    int goodNodes(TreeNode* root) {
        int countOfGoodNodes = 0;
        int maxi = INT_MIN;
        Helper(root, countOfGoodNodes, maxi);
        return countOfGoodNodes;
    }
    void Helper(TreeNode* root, int &countOfGoodNodes, int &maxi){
        if(!root)return;
        maxi = max(maxi, root -> val);
        if(root -> val >= maxi)countOfGoodNodes++;
        int maxTillNow = maxi;
        Helper(root -> left, countOfGoodNodes, maxi);
        Helper(root -> right, countOfGoodNodes, maxTillNow);
    }
};