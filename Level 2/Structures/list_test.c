#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "door_struct.h"

void display(struct node *start) {
    while(start) {
        printf("door: %d, status: %d\n", start->id, start->status);
        start = start->next;
    }
}

void check(struct node *start) {
    puts("-----------------------");
    printf("Tests for adding elements to the list:\n");
    display(start);
    int count = 0, i = 0, last;
    while(start) {
        if (start->id == i) {
            count++;
        }
        last = start->id;
        start = start->next;
        i++;
    }
    if (count == last + 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    puts("-----------------------\n");
}

void check_remove(struct node *start, int removed_id, int new_length) {
    puts("-----------------------");
    printf("Tests for removing elements from the list:\n");
    display(start);
    int count = 0, id_not_removed = 0;
    while(start) {
        count++;
        if (start->id == removed_id) { id_not_removed = 1; }
        start = start->next;
    }
    if (count == new_length && !id_not_removed) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    puts("-----------------------\n");
}

void tests() {
    struct door *first_door = malloc(sizeof(struct door));
    first_door->id = 0,
    first_door->status = 0;
    struct node *start = init(first_door);
    check(start);
    struct door *second_door = malloc(sizeof(struct door));
    second_door->id = 1,
    second_door->status = 0;
    struct node *second = add_door(start, second_door);
    check(start);
    struct door *third_door = malloc(sizeof(struct door));
    third_door->id = 2,
    third_door->status = 1;
    struct node *third = add_door(second, third_door);
    check(start);
    struct door *fourth_door = malloc(sizeof(struct door));
    fourth_door->id = 3,
    fourth_door->status = 0;
    struct node *fourth = add_door(third, fourth_door);
    check(start);
    struct door *fifth_door = malloc(sizeof(struct door));
    fifth_door->id = 4,
    fifth_door->status = 1;
    struct node *fifth = add_door(fourth, fifth_door);
    check(start);
    remove_door(third, start);
    check_remove(start, 2, 4);
    remove_door(fifth, start);
    check_remove(start, 4, 3);
    remove_door(fourth, start);
    check_remove(start, 3, 2);
    struct node *door_found = find_door(1, start);
    display(door_found);
    free(first_door);
    free(second_door);
    free(third_door);
    free(fourth_door);
    free(fifth_door);
}

int main() {
    tests();  
    return 0;
}
