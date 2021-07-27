#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
    protected:
        bool isEqual(TreeNode *pRoot1, TreeNode *pRoot2)
        {
            std::queue<TreeNode *> queue1, queue2;

            queue1.push(pRoot1);
            queue2.push(pRoot2);

            while (!queue2.empty())
            {
                TreeNode *node1 = queue1.front();
                queue1.pop();

                TreeNode *node2 = queue2.front();
                queue2.pop();

                if (node1->val != node2->val)
                {
                    return false;
                }

                if (node2->left)
                {
                    if (node1->left == NULL) return false;
                    queue1.push(node1->left);
                    queue2.push(node2->left);
                }

                if (node2->right)
                {
                    if (node1->right == NULL) return false;
                    queue1.push(node1->right);
                    queue2.push(node2->right);
                }
            }

            return true;
        }

    public:

        bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
        {
            if (pRoot1 == NULL || pRoot2 == NULL)
            {
                return false;
            }

            std::queue<TreeNode *> queue;

            queue.push(pRoot1);

            while (!queue.empty())
            {
                TreeNode *node = queue.front();
                queue.pop();

                if (isEqual(node, pRoot2))
                {
                    return true;
                }

                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }

            return false;
        }
};

int main()
{
    std::cout << "Hello World!" << std::endl;

    return 0;
}
