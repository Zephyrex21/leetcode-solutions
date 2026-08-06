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
private:
    void inorder( TreeNode *root , vector<int>& ans ){

        // left -> root -> right
        if( root == NULL ){
            return ;
        }

        // inorder ( root -> left )
        inorder( root -> left , ans );

        // root 
        ans.push_back( root -> val );

        // inorder( root -> right )
        inorder( root -> right , ans  );

    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder( root , ans );
        return ans;
    }
};