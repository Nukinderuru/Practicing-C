#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct tree *bstree_create_node(int info) {
    struct tree *r = (struct tree *)malloc(sizeof(struct tree));
    if (!r) {
        printf("Memory wasn't allocated, try again.\n");
        return NULL;
    }
    r->left = NULL;
    r->right = NULL;
    r->info = info;
    return r;
}

struct tree *bstree_insert(struct tree *root, struct tree *r, int info) {
    if (!r) {
        r = bstree_create_node(info);
        if (!root) return r;
        if (info < root->info) root->left = r;
        else root->right = r;
        return r;
    }
    if (info < r->info) bstree_insert(r, r->left, info);
    else bstree_insert(r, r->right, info);
    return root;
}

void print_root(struct tree *root) {
    if (root->info) {
        printf("The root is: %d\n", root->info);
    } else {
        printf("There's no info in the root.\n");
    }
}

void print_sideways(struct tree *root, int l) {
    int i;
    if (root == NULL) return; 
    print_sideways(root->right, l + 1);
    for (i = 0; i < l; ++i) printf(" ");
    printf("%d\n", root->info);
    print_sideways(root->left, l + 1);
    
}

void bstree_apply_infix(struct tree *root) {
    if (!root) return;
    bstree_apply_infix(root->left);
    if (root->info) printf("%d ", root->info);
    bstree_apply_infix(root->right);
}

void bstree_apply_prefix(struct tree *root) {
    if (!root) return;
    if (root->info) printf("%d ", root->info);
    bstree_apply_prefix(root->left);
    bstree_apply_prefix(root->right);
}

void bstree_apply_postfix(struct tree *root) {
    if (!root) return;
    bstree_apply_postfix(root->left);
    bstree_apply_postfix(root->right);
    if (root->info) printf("%d ", root->info);
}

struct tree *search_tree(struct tree *root, int key) {
    if (!root) return root;
    while (root->info != key) {
        if(key < root->info) root = root->left;
        else root = root->right;
        if (root == NULL) break;
    }
    return root;
}

struct tree *delete_tree(struct tree *root, int key) {
    struct tree *p = NULL, *p2 = NULL;
    if (!root) return root;
    if (root->info == key) {
        if (root->left == root->right) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            p = root->right;
            free(root);
            return p;
        } else if (root->right == NULL) {
            p = root->left;
            free(root);
            return p;
        } else {
            p2 = root->right;
            p = root->right;
            while (p->left) p = p->left;
            p->left = root->left;
            free(root);
            return p2;
        }
    }
    if (root->info < key) root->right = delete_tree(root->right, key);
    else root->left = delete_tree(root->left, key);
    return root;
}
