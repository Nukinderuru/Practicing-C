#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "door_struct.h"

struct node *init(struct door *door) {
    struct node *init = malloc(sizeof(struct node));
    init->id = door->id;
    init->status = door->status;
    init->next = NULL;
    return init;
}

struct node *add_door(struct node *elem, struct door *door) {
    struct node *cur = malloc(sizeof(struct node));
    cur->id = door->id;
    cur->status = door->status;
    cur->next = NULL;
    if (!elem->next) {
        elem->next = cur;
        return cur;
    } else {
        cur->next = elem->next;
        elem->next = cur;
        return cur;
    }
    return NULL;
}

struct node *find_door(int door_id, struct node *root) {
    while (root) {
        if (root->id == door_id) return root;
        root = root->next;
    }
    return NULL;
}

struct node *remove_door(struct node *elem, struct node *root) {
    struct node *prev = root;
    if (root->id == elem->id) {
        root = root->next;
        return root;
    } else {
        while (root) {
            if (!root->next) {
                prev->next = NULL;
                return prev;
            }
            else if (root->id == elem->id) {
                prev->next = root->next;
                return root;
            }
            prev = root;
            root = root->next;
        }
    }
    return NULL;
}

void destroy(struct node *root) {
    struct node *cur = root;
    struct node *next = malloc(sizeof(struct node));
    for (; cur != NULL; cur = next) {
        next = cur->next;
        free(cur);
    }
}
