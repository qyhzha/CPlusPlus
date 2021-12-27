/*
 * @Author: yonghang.qin
 * @Date: 2021-11-25 09:36:39
 * @LastEditors: yonghang.qin
 * @LastEditTime: 2021-12-27 15:50:49
 * @Description:
 */
#include <stdbool.h>
#include <limits.h>

class binarySearchTree
{
protected:
    int val;
    binarySearchTree *left;
    binarySearchTree *right;

    bool is_binary_search_tree(binarySearchTree *root, int min, int max);

public:
    bool isValidBST(void);
};

bool binarySearchTree::is_binary_search_tree(binarySearchTree *root, int min, int max)
{
    if (root->val < min || root->val > max)
    {
        return false;
    }

    if (root->left)
    {
        if (!is_binary_search_tree(root->left, min, root->val))
        {
            return false;
        }
    }

    if (root->right)
    {
        if (!is_binary_search_tree(root->right, root->val, max))
        {
            return false;
        }
    }

    return true;
}

bool binarySearchTree::isValidBST(void)
{
    if (this->left && !is_binary_search_tree(this->left, INT_MIN, this->val))
    {
        return false;
    }

    if (this->right && !is_binary_search_tree(this->right, this->val, INT_MAX))
    {
        return false;
    }

    return true;
}
