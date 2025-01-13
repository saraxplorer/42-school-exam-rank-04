typedef struct s_btree
    {
        int value;
        struct s_btree *left;
        struct s_btree *right;
    } t_btree;
