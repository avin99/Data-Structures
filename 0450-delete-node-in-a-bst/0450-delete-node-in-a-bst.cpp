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
TreeNode* parentNode = NULL;
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;

        TreeNode* keyNode = isKeyPresent(root, key);
        if(!keyNode){
            return root;
        }
        TreeNode* newRoot = helper(root, keyNode, key);
        return newRoot;
    }
    TreeNode* isKeyPresent(TreeNode* root, int key){
        if(!root)return NULL;
        if(root -> val == key) return root;
        parentNode = root;
        if(root -> val < key)return isKeyPresent(root -> right, key);
        else return isKeyPresent(root -> left, key);
    }

    TreeNode* helper(TreeNode* root, TreeNode* keyNode, int key){
        TreeNode *newNode = NULL;
        if(keyNode -> left && keyNode -> right){
            TreeNode *rightChild = keyNode -> left -> right;
            newNode = keyNode -> left;
            newNode -> right = keyNode -> right;
            TreeNode *node = newNode -> right;
            while(node -> left){
                node = node -> left;
            }
            node -> left = rightChild;
        }else if(keyNode -> left == NULL){
            newNode = keyNode -> right;
        }else {
            newNode = keyNode -> left;
        }
        if(parentNode == NULL)return newNode;
        if(keyNode -> val > parentNode -> val){
            parentNode -> right = newNode;
        }else{
            parentNode -> left = newNode;
        }  
        return root;
    }
};