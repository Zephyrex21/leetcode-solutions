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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool LeftToRight = true;

        while(!q.empty()) {

            int size = q.size();

            vector<int> ans(size);

            // Process one level
            for(int i = 0; i < size; i++) {

                TreeNode* frontNode = q.front();
                q.pop();

                // find index
                int index = LeftToRight ? i : size - i - 1;

                ans[index] = frontNode->val;

                if(frontNode->left) {
                    q.push(frontNode->left);
                }

                if(frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // change direction
            LeftToRight = !LeftToRight;

            result.push_back(ans);
        }

        return result;
    }
};