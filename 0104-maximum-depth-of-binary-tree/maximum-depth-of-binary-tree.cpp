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
    int maxDepth(TreeNode* root) {

        // base case
        if ( root == NULL ){
            return 0;
        }

        // height of left sub-tree
        int left = maxDepth( root -> left );

        // height of right sub-tree
        int right = maxDepth( root -> right );
        
        // maximum height
        int ans = max( left , right ) + 1 ;

        return ans;
    }
};