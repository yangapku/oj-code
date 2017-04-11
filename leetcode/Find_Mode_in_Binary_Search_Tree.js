/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var record = {};
var findMode = function (root) {
    record = {};
    if (root !== null) visit(root);
    var result = [];
    var count = 0;
    for (var key in record) {
        if (record[key] > count) {
            result = [parseInt(key)];
            count = record[key];
        } else if (record[key] === count) {
            result.push(parseInt(key));
        }
    }
    return result;
};

function visit(node) {
    if (node === null) return;
    var value = node.val;
    if (record[value] === undefined) {
        record[value] = 1;
    } else {
        record[value]++;
    }
    visit(node.left);
    visit(node.right);
    return;
}
