// leetcode 144  Binary Tree Preorder Traversal using stack

/*
    preorder traversal
    Using stack TC- O(n) & SC- O(n)
*/

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr != NULL || !st.empty())
        {
            if (curr)
            {
                ans.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        return ans;
    }
};