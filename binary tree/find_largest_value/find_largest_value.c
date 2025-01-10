#include <limits.h>
typedef struct s_tree
{
    int value;
    struct s_tree *left;
    struct s_tree *right;
}t_tree;

int find_largest(t_tree *tree)
{
    if (!tree)
        return (INT_MIN);
    int max = tree->value;
    int max_left = find_largest(tree->left);
    int max_right = find_largest(tree->right);
    if (max_left > max)
        max = max_left;
    if (max_right > max)
        max = max_right;
    return (max);
}