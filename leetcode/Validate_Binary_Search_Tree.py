# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildMax(self,root):
        maxRoot=TreeNode(root.val)
        if root.left!=None:
            lsubTree=self.buildMax(root.left)
            maxRoot.left=lsubTree
            maxRoot.val=max(maxRoot.val,lsubTree.val)
        if root.right!=None:
            rsubTree=self.buildMax(root.right)
            maxRoot.right=rsubTree
            maxRoot.val=max(maxRoot.val,rsubTree.val)
        return maxRoot
    
    def buildMin(self,root):
        minRoot=TreeNode(root.val)
        if root.left!=None:
            lsubTree=self.buildMin(root.left)
            minRoot.left=lsubTree
            minRoot.val=min(minRoot.val,lsubTree.val)
        if root.right!=None:
            rsubTree=self.buildMin(root.right)
            minRoot.right=rsubTree
            minRoot.val=min(minRoot.val,rsubTree.val)
        return minRoot
    
    def visit(self,root,maxRoot,minRoot):
        if root.left!=None:
            if maxRoot.left.val>=root.val:
                return False
            if not self.visit(root.left,maxRoot.left,minRoot.left):
                return False
        if root.right!=None:
            if minRoot.right.val<=root.val:
                return False
            if not self.visit(root.right,maxRoot.right,minRoot.right):
                return False
        return True
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        maxTree=self.buildMax(root)
        minTree=self.buildMin(root)
        return self.visit(root,maxTree,minTree)
