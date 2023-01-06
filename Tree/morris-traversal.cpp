/*
    Morris traversal to print in-order traversal
    TC- O(n) and SC- O(1)
*/

class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        // Morris traversal
        Node *curr = root;
        vector<int> inorder;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *temp = curr->left;
                while (temp->right != NULL && temp->right != curr)
                {
                    temp = temp->right;
                }

                if (temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }

                if (temp->right == curr)
                {
                    inorder.push_back(curr->data);
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};







/*
    Morris traversal to print pre-order traversal
*/

class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        // Morris traversal
        Node *curr = root;
        vector<int> preorder;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *temp = curr->left;
                while (temp->right != NULL && temp->right != curr)
                {
                    temp = temp->right;
                }

                if (temp->right == NULL)
                {
                    temp->right = curr;
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }

                if (temp->right == curr)
                {
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};