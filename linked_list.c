#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

typedef struct node_t {
    int val;
    struct node_t* next;
} node_t;

void throw_error (const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

node_t* init_list () {
    return NULL;
}

node_t* create_node(int val) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void print_list(node_t* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void append_node(node_t** head, int val) {
    node_t* new_node = create_node(val);
    if (*head == NULL) {
        *head = new_node;
        return;
    } 

    node_t* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void prepend_node(node_t** head, int val) {
    node_t* new_node = create_node(val);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    new_node->next = *head;
    *head = new_node;
}

void add_node(node_t** head, int val, int index) {
    node_t* new_node = create_node(val);
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    if (index <= 0) {
        prepend_node(head, val);
        return;
    }

    node_t* prev = NULL;
    node_t* temp = *head;
    for (int i = 0; i < index; ++i) {
        if (temp->next == NULL) {
            temp->next = new_node;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->next != NULL) {
        prev->next = new_node;
        new_node->next = temp;
        return;
    }
    
    append_node(head, val);
}

int delete_node_by_val (node_t** head, int val) {
    int ret_val = 0;

    if (*head == NULL) {
        throw_error("List is already empty"); 
    }
    
    node_t* prev = NULL;
    node_t* temp = *head;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
        if (temp->val == val) {
            ret_val = temp->val;
            prev->next = temp->next ? temp->next : NULL;
            free(temp);
            return ret_val;
        }
    }

    throw_error("No found value to delete");
    return ret_val;
}

int delete_node_by_index (node_t** head, int index) {
    int ret_val = 0;

    if (*head == NULL) {
        throw_error("List is already empty!");
    }
    
    if (index < 0) {
        throw_error("Invalid index!");
    }

    if (index == 0) {
        node_t* deleted_node = *head;
        ret_val = deleted_node->val;
        *head = deleted_node->next;
        free(deleted_node);
        return ret_val;
    }

    node_t* prev = NULL;
    node_t* temp = *head;
    int j = 0;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
        if (j == index) {
            ret_val = temp->val;
            prev->next = temp->next ? temp->next : NULL;
            free(temp);
            return ret_val;
        }
        j++;
    }
 
    throw_error("Invalid index!");
    return ret_val;
}

bool find_node (node_t* head, int val) {
    while (head->next) {
        if (head->val == val) {
            return true;
        }
        head = head->next;
    }

    return false;
}

int find_node_index (node_t* head, int val) {
    int index = 0;

    while (head->next) {
        if (head->val == val) {
            return index;
        }
        head = head->next;
        ++index;
    }

    return -1;
}

int find_node_last_index (node_t* head, int val) {
    int index = 0;
    bool is_found = false;
    int candidate = index;

    while (head->next) {
        if (head->val == val) {
            is_found = true;
            candidate = index;
        }
        head = head->next;
        ++index;
    }

    return is_found ? candidate : -1;
}

void reverse_list (node_t** head) {
    node_t* next = NULL;
    node_t* prev = NULL;
    node_t* temp = *head;

    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    *head = prev;
}

int get_list_size (node_t* head) {
    int count = 0;

    while (head) {
        head = head->next;
        ++count;
    }

    return count;
}

void free_list (node_t** head) {
    node_t* next = NULL;
    while (*head) {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
}

