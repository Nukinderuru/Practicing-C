#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void bst_create_test() {
    struct tree *one = bstree_create_node(8);
    struct tree *two = bstree_create_node('a');
    struct tree *three = bstree_create_node(-0);
    struct tree *four = bstree_create_node(0);
    print_root(one);
    print_root(two);
    print_root(three);
    print_root(four);
}

void bstree_apply_test(struct tree *root) {
    bstree_apply_infix(root);
    printf("\n");
    bstree_apply_prefix(root);
    printf("\n");
    bstree_apply_postfix(root);
    printf("\n");
}

void bst_insert_test() {
    struct tree *root_one = bstree_create_node(8);
    struct tree *stree1_one = bstree_insert(root_one, root_one, 6);
    struct tree *stree1_two = bstree_insert(root_one, root_one, 10);
    struct tree *stree1_three = bstree_insert(root_one, stree1_one, 12);
    struct tree *stree1_four = bstree_insert(root_one, root_one, 3);
    bstree_insert(root_one, stree1_one, 4);
    bstree_insert(root_one, stree1_two, 15);
    bstree_insert(root_one, stree1_one, 9);
    bstree_insert(root_one, stree1_one, 7);
    bstree_insert(root_one, stree1_two, 5);
    bstree_insert(root_one, stree1_two, 1);
    bstree_insert(root_one, stree1_three, 14);
    bstree_insert(root_one, stree1_three, 13);
    bstree_insert(root_one, stree1_four, 2);
    bstree_insert(root_one, stree1_four, 11);
    bstree_apply_test(root_one);
    print_sideways(root_one, 0);
    printf("\n");
    print_sideways(search_tree(root_one, 11), 0);
    printf("\n");
    delete_tree(root_one, 5);
    delete_tree(root_one, 12);
    delete_tree(root_one, 2);
    delete_tree(root_one, 15);
    print_sideways(root_one, 0);
    bstree_apply_test(root_one);
}

int main() {
    #ifdef BST_CREATE_TEST
        bst_create_test();
    #elif BST_INSERT_TEST
        bst_insert_test();
    #elif BST_APPLYF_TEST
        bst_insert_test();
    #endif
    return 0;
}
