#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "door_struct.h"

struct node* init(struct door* door) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root -> field = door;
    root -> next = NULL;
    return root;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* temp, *p;
    p = elem -> next;
    elem -> next = temp;
    temp -> field = door;
    temp -> next = p;
    return temp;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* elem = root;
    while (elem != NULL) {
        if (elem -> field -> id == door_id) {
            return elem;
        }
        elem = elem -> next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* prev = root;
    while (prev -> next != elem) {
        prev = prev -> next;
    }
    prev -> next = elem -> next;
    free(elem);
    return prev;
}

void destroy(struct node* root) {
    struct node* elem = root;
    while (elem != NULL) {
        struct node* next = elem -> next;
        free(elem);
        elem = next;
    }
}

void print_struct(struct node* root) {
    struct node *p;
    if (root != NULL) {
        p = root;
        while (p -> next != NULL) {
            printf("id = %d status =%d\n", p -> field -> id, p -> field -> status);
            p = p -> next;
        }
    } else {
        printf("No");
    }
}
