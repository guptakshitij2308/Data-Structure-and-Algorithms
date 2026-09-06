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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        int ans=1;
        while(!q.empty()) {
            int size=q.size();
            int minn,maxx;
            minn=q.front().second;
            for(int i=0;i<size;i++) {
                auto front=q.front();
                q.pop();
                TreeNode* node=front.first;
                long long int num=front.second;
                if(i==0) minn=num;
                if(i==size-1) maxx=num;
                if(node->left) {
                    q.push({node->left,2*(num-minn)+1});
                }
                if(node->right) {
                    q.push({node->right,2*(num-minn)+2});
                }
            }
            ans=max(ans,maxx-minn+1);
        }
        return ans;
    }
};