#include <stdio.h>
#include "linked_list.h"

int main() {
    node_t* head = init_list();

    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);
    append_node(&head, 4);

    prepend_node(&head, 0);
    prepend_node(&head, -1);
    prepend_node(&head, -2);

    add_node(&head, 1, 0);
    add_node(&head, 2, 1);
    add_node(&head, 3, -1);
    add_node(&head, 13, 2);

    print_list(head);

    reverse_list(&head);
    
    printf("list size: %d\n", get_list_size(head));
    print_list(head);
    
    free_list(&head);

    print_list(head);

    return 0;
}

