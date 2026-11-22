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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> level;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
            TreeNode* tmp=q.front();
            q.pop();
            


            level.push_back(tmp->val);
         

            if(tmp->left != NULL)
                q.push(tmp->left);
            if(tmp->right != NULL)
                q.push(tmp->right);
            }
            ans.push_back(level);

        }
    
        reverse(ans.begin(),ans.end());

    return ans;
        
    }
};
