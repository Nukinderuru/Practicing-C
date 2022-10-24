#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"
#include "list.h"

void initialize_doors(struct door *doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void close_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void sort_doors(struct door *doors) {
    int temp;
    for (int i = DOORS_COUNT - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (doors[j].id > doors[j + 1].id) {
                temp = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = temp;
            }
        }
    }
}

void print_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    close_doors(doors);
    sort_doors(doors);
    print_doors(doors);
    return 0;
}
