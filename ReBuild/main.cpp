#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
protected:
    TreeNode *reBuild(vector<int> pre, int pre_begin, vector<int> vin, int vin_begin, int len)
    {
        TreeNode *node = new TreeNode(pre[pre_begin]);

        int cur = -1;
        for (int i = vin_begin; i < static_cast<int>(vin.size()); i++)
        {
            if (vin[i] == pre[pre_begin])
            {
                cur = i;
                break;
            }
        }

        if (cur == -1) return NULL;

        int left_len = cur - vin_begin;
        int right_len = len - left_len - 1;

        if (left_len > 0) node->left = reBuild(pre, pre_begin + 1, vin, vin_begin, left_len);
        if (right_len > 0) node->right = reBuild(pre, pre_begin + 1 + left_len, vin, vin_begin + 1 + left_len, right_len);

        return node;
    }

public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return reBuild(pre, 0, vin, 0, pre.size());
    }
};

int main()
{
    TreeNode *node = Solution().reConstructBinaryTree({1,2,4,7,3,5,6,8,9}, {4,7,2,1,5,3,8,6,10});

    queue<TreeNode *> queue;

    queue.push(node);

    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.pop();

        cout << "val = " << node->val << endl;

        if (node->left != NULL) queue.push(node->left);
        if (node->right != NULL) queue.push(node->right);
    }

    return 0;
}
