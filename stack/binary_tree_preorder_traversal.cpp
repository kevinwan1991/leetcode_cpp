    //standard solution:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int> nodes;
        std::stack<TreeNode*> stack;
        
        auto curr = root;
        while (!stack.empty() || curr)
        {
            if (curr)
            {
                nodes.push_back(curr->val);
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
                curr = curr->right;
            }
        }
        return nodes;
    }



    //simpler solution:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if (!root)  return {};
        
        std::vector<int> nodes;
        std::stack<TreeNode*> s;
        
        s.push(root);
        while (!s.empty()) 
        {
            TreeNode* node = s.top(); s.pop();
            nodes.push_back(node->val);
            
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
       
        return nodes;
    }
