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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> record = vector<int>();
        visit(record, 0, root);
        return record[record.size()-1];
    }

    void visit(vector<int> &rec, int level, TreeNode *ptr) {
        if (ptr == NULL) return;
        if (level >= rec.size()) {
            rec.push_back(ptr->val);
        }
        visit(rec, level + 1, ptr->left);
        visit(rec, level + 1, ptr->right);
        return;
    }
};
