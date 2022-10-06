#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    doors_sort(doors);
    doors_status(doors);
    doors_output(doors);
    return 0;
}

