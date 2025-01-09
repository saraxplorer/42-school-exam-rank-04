
#include <stdlib.h>

typedef struct s_tree
{
    int value;
    struct s_tree *left;
    struct s_tree *right;
}t_tree;

int tree_sum(t_tree *tree)
{
    if (!tree)
        return (NULL);
    return (tree_sum(tree->left->value + tree_sum(tree->right->value) + tree->value));
}