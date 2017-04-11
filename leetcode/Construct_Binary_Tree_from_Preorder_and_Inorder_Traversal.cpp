/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int b1,int e1,int b2,int e2){
        if(b1==e1) return NULL;
        int mid;
        for(int j=b2;j<e2;j++){
            if(inorder[j]==preorder[b1]){
                mid=j;
                break;
            }
        }
        TreeNode* ptr=new TreeNode(inorder[mid]);
        ptr->left=build(preorder,inorder,b1+1,b1+1+mid-b2,b2,mid);
        ptr->right=build(preorder,inorder,b1+1+mid-b2,e1,mid+1,e2);
        return ptr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
};
