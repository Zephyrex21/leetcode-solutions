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
    void preorder( TreeNode *root , vector<int>& ans ){

        // left -> root -> right
        if( root == NULL ){
            return ;
        }

        // root 
        ans.push_back( root -> val );

        // preorder ( root -> left )
        preorder( root -> left , ans );

        // preorder( root -> right )
        preorder( root -> right , ans  );

    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder( root , ans ) ;
        return ans; 
    }
};