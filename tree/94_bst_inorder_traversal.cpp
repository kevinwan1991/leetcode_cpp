/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }

    void inorderTraversal(TreeNode* node, vector<int>& result)
    {
        if (node)
        {
            inorderTraversal(node->left, result);
            result.push_back(node->val);
            inorderTraversal(node->right, result);
        }
    }
};

class BetterSolution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        std::stack<TreeNode*> stack;
        auto current = root;
        auto runnable = true;

        while (runnable)
        {
            if (current)
            {
                stack.push(current);
                current = current->left;
            }
            else if (!stack.size())
            {
                runnable = false;
            }
            else
            {
                current = stack.top();
                result.push_back(current->val);
                stack.pop();
                current = current->right;
            }
        }
        return result;
    }
};





