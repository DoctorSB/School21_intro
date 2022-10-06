#include "door_struct.h"


void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
void doors_sort(struct door* doors) {
    int buffer;
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int j = i + 1; j < DOORS_COUNT; j++) {
            if (doors[i].id > doors[j].id) {
                buffer = doors[i].id;
                doors[i].id = doors[j].id;
                doors[j].id = buffer;
            }
        }
    }
}
void doors_status(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}
void doors_output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i == DOORS_COUNT - 1) {
            printf("%d, %d", doors[i].id, doors[i].status);
        } else {
            printf("%d, %d\n", doors[i].id, doors[i].status);
        }
    }
}
