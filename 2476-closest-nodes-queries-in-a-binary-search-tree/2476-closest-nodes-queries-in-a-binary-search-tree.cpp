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
    vector<int>pq;
    void helper(TreeNode* root)
    {
           if(root == NULL)return;        
           helper(root -> left);
           pq.push_back(root -> val);
           helper(root -> right);                
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ans;
        helper(root);
        // cout<<"[ ";
        // for(auto &it : pq)cout<<it<<" ";
        // cout<<"]"<<endl;
        //return ans;
        
    for(auto &q : queries)
    {
        int i = -1, j = -1;
        auto it = lower_bound(pq.begin(), pq.end(), q);
        if(it != pq.end())j = *it;        
        if(it != pq.end() && *it == q)
        {
            i = *it;
            
        }
        else
        {            
            if(it != pq.begin())
            {
                it--;
                i = *it;
            }
        }
        ans.push_back({i, j});
    }
        
    return ans;  
    }
};