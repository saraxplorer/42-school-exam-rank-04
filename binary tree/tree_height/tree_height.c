typedef struct s_tree
{
    int value;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

int tree_height(t_tree *tree)
{
    if (!tree)
        return (-1);//The height of an empty tree is `-1`, coz for a tree with only one node, it is `0`.
    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);
    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

//return the larger one plus 1

