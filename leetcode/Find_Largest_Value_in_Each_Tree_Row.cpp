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
    vector<int> largestValues(TreeNode *root) {
        vector<int> record = vector<int>();
        visit(record, 0, root);
        return record;
    }

    void visit(vector<int> &rec, int level, TreeNode *ptr) {
        if (ptr == NULL) return;
        if (level >= rec.size()) {
            rec.push_back(ptr->val);
        } else {
            rec[level] = ptr->val > rec[level] ? ptr->val : rec[level];
        }
        visit(rec, level + 1, ptr->left);
        visit(rec, level + 1, ptr->right);
        return;
    }
};
