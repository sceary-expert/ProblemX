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
    bool findTarget(TreeNode* root, int k) {
           queue<TreeNode*> q;
        set<int> myset; //values seen
        TreeNode* cur;
        
        q.push(root);
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur==NULL) break;
            
            if(myset.find(k-cur->val)!=myset.end()){
                return true;
            }
            myset.insert(cur->val);
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        
        return false;
        
    }
};