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
    void postorder( TreeNode *root , vector<int>& ans ){

        // left -> root -> right
        if( root == NULL ){
            return ;
        }

        // postorder ( root -> left )
        postorder( root -> left , ans );

        // postorder( root -> right )
        postorder( root -> right , ans  );

        // root 
        ans.push_back( root -> val );

    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder( root , ans );
        return ans ; 
    }
};