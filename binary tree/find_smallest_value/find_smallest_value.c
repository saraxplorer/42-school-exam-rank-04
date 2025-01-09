#include <limits.h>

typedef struct s_tree
{
    int value;
    struct s_tree *left;
    struct s_tree *right;
}t_tree;

int smallest_val(t_tree *tree)
{
    if (!tree)
        return (INT_MAX);
    int min = tree->value;
    int left_min = smallest_val(tree->left);
    int right_min = smallest_val(tree->right);
    if (left_min < min)
        min = left_min;
    else if (right_min < min)
        min = right_min;
    return (min);
}

//The base case of the recursion is when tree is NULL. This indicates that we have reached the end of a branch of the tree (i.e., a leaf node's child).
//When comparing the values during the recursion, you want to make sure that an empty subtree (or the absence of a subtree) doesn't interfere with finding the minimum value.