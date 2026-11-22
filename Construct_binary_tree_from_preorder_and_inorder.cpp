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
 int preIndex = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inStart = 0;
        int inEnd = inorder.size()-1;

        return solve(preorder, inorder, inStart, inEnd);
    }


     TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int inStart, int inEnd) {

        if(inStart > inEnd) {
            return NULL;
        }

        int val = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(val);

        int pos = 0;

        for(int i = inStart; i <= inEnd; i++) {
            if(inorder[i] == val) {
                pos = i;
                break;
            }
        }

        root->left = solve(preorder, inorder, inStart, pos-1);

        root->right = solve(preorder, inorder, pos+1, inEnd);

        return root;
    }
};
