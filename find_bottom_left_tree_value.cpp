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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int pp;
       
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
               
                TreeNode* tmp=q.front();
                q.pop();

                vector<int> ans;
                ans.push_back(tmp->val);

                if(tmp->right!=NULL)
                    q.push(tmp->right);
                if(tmp->left != NULL)
                    q.push(tmp->left);

                pp=ans.back();
            }
        }

        return pp;
    }
};

