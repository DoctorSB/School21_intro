#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

struct door {
    int id, status;
};

void initialize_doors(struct door* doors);
void doors_sort(struct door* doors);
void doors_status(struct door* doors);
void doors_output(struct door* doors);

#endif  //  SRC_DOOR_STRUCT_H_
