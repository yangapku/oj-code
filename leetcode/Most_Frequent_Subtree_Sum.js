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
var findFrequentTreeSum = function (root) {
    record = {};
    if(root!==null) calculate(root);
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

function calculate(node) {
    var sum = node.val;
    if (node.left !== null) sum += calculate(node.left);
    if (node.right !== null) sum += calculate(node.right);
    if (record[sum] === undefined) {
        record[sum] = 1;
    } else {
        record[sum]++;
    }
    return sum;
}
