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
