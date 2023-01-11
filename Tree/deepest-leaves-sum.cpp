// leetcode 1302 Deepest Leaves Sum

/*
    Intuition :- apply bfs which will find all the levels sum and by finding all the levels it will find the end level sum which we can return
    TC- O(n) as we are visiting every node ones  SC- O(width)
*/

class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == NULL)
            {
                if (q.empty())
                {
                    return sum;
                }
                sum = 0;
                q.push(NULL);
                continue;
            }
            sum += node->val;
            if (node->left != NULL)
            {
                q.push(node->left);
            }

            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        return sum;
    }
};