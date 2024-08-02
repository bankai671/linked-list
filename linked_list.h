#include <stdbool.h>

typedef struct node_t node_t;

node_t* init_list(void);
node_t* create_node (int val);
void append_node (node_t** head, int val);
void prepend_node (node_t** head, int val);
void add_node (node_t** head, int val, int index);
int delete_node_by_val (node_t** head, int val);
int delete_node_by_index (node_t** head, int index);
void print_list (node_t* head);
bool find_node (node_t* head, int val);
int find_node_index (node_t* head, int val);
int find_node_last_index (node_t* head, int val);
void reverse_list (node_t** head);
int get_list_size (node_t* head);
void free_list (node_t** head);
