#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void print_list(node_t *start_node) {
    node_t *current_node = start_node;
    while (current_node != NULL) {
        printf("%d ", current_node->val);
        current_node = current_node->next;
    }
    printf("\n");
}

void insert_node(node_t *start_node, node_t *new_node) {
    node_t *current_node = start_node;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void delete_node(node_t *start_node, int index) {
    node_t *current_node = start_node;
    node_t *prev_node = NULL;
    int count = 0;
    
    while (count != index) {
        prev_node = current_node;
        current_node = current_node->next;
        ++count;
    }
    
    if (prev_node != NULL) {
        prev_node->next = current_node->next;
    }
}

node_t create_node(int val) {
    node_t res = {.val = val, .next = NULL};
    return res;
}

int main() {
    node_t start_node = create_node(1);
    print_list(&start_node);
    node_t node2 = create_node(2);
    insert_node(&start_node, &node2);
    node_t node3 = create_node(3);
    insert_node(&start_node, &node3);
    print_list(&start_node);
    delete_node(&start_node, 1);
    print_list(&start_node);
    return 0;
}
