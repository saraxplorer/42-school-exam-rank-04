#include "ft_btree.h"

int tree_height(t_btree *tree)
{
    if (!tree)
        return (0);
    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);
    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

//Although The height of an empty tree is `-1`, coz for a tree with only one node, it is `0`.
//we return 0 here because the subject asked so.
//return the larger one plus 1

