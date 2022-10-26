/*
    A binary search tree
*/

#ifndef BST_H
#define BST_H

struct tree {
    int info;
    struct tree *left;
    struct tree *right;
};

struct tree *bstree_create_node(int info);
struct tree *bstree_insert(struct tree *root, struct tree *r, int info);
void print_root(struct tree *root);
void print_sideways(struct tree *root, int l);
void bstree_apply_infix(struct tree *root);
void bstree_apply_prefix(struct tree *root);
void bstree_apply_postfix(struct tree *root);
struct tree *search_tree(struct tree *root, int key);
struct tree *delete_tree(struct tree *root, int key);

#endif