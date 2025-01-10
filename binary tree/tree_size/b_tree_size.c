
//The 1 + represents counting the current node itself.
//In a binary tree, you need to count the root node and all nodes in its left and right subtrees.

typedef struct s_tree
{
    int value;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

int tree_size(t_tree *tree)
{  
    if (!tree)
        return (0);
    return(1 + tree_size(tree->left) + tree_size(tree->right));
}

//the number of recursion calls corresponds to the number of nodes in the tree (not just the subtrees). Here's how:

//Each recursion call is made for one node in the tree, whether it’s the root, a left child, or a right child.
////If there are 
//𝑁
//N nodes in the entire tree, the function will be called exactly 
//𝑁
//+
//1
//N+1 times:
//𝑁
//N times for the actual nodes.
//+
//1
//+1 because of the final NULL check when reaching a leaf node's child.
//Example:
//For a tree with 5 nodes:

//markdown
//Copy code
//      1
//     / \
//    2   3
//     / \
//    4   5
//The function is called for each node (1, 2, 3, 4, 5).
//Additional calls are made for the NULL left and right children of 4, 5, 3.
//So, the number of recursion calls includes one call per node plus calls for each NULL pointer, ensuring the entire structure is traversed.













