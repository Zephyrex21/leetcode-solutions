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
    void preorder( TreeNode* &root ,  vector<TreeNode* > &arr  ){
    
        // base case 
        if( root == NULL ){
            return;
        }
        arr.push_back(root);            // push node data into vector
        preorder( root->left , arr );   // recursive call for left sub-tree 
        preorder( root->right , arr );  // recursive call for right sub-tree    
    }
public:
    void flatten(TreeNode* root) {
        // base case
        if( root == NULL ){
            return ;
        }

        // using vector to store the traversal
        vector<TreeNode* > arr;

        // Step1: Store in-order Traversal
        preorder( root , arr );

        //Step:2  connect nodes to linked list
        for(  int i = 0 ; i < arr.size()-1 ; i++ ){
            arr[i]->left = NULL;
            arr[i]->right = arr[i + 1];
        } 

        // Step3: Last Node -> NULL ( for both left n right )
        arr[ arr.size()-1 ]->left = NULL;
        arr[ arr.size()-1 ]->right = NULL;
    }
};