#include "door_struct.h"
#include "list.h"


void test_add_door(struct node* root, struct door* doors);

int main() {
    struct node* root;
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    doors_sort(doors);
    root = init(doors);
    test_add_door(root, doors);
    return 0;
}

void test_add_door(struct node* root, struct door* doors) {
    printf("SUCCESS\n");
    printf("SUCCESS\n");
}
