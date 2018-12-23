
typedef struct node
{
    int val;
    struct node* next;
} node_t;

typedef enum {
    LL_SUCCESS = 0,
    LL_ERROR = 1,
    LL_ERROR__INVALID_PARAM = 2,
} func_return_t;

node_t* add_node_to_end(node_t* headptr, int val);
node_t* add_node_to_beggining(node_t* headptr, int val);
node_t* add_node_after_val(node_t* headptr, int val, int val_to_add_after);
node_t* add_node_before_val(node_t* headptr, int val, int val_to_add_before);

node_t* create_linked_list(node_t* headptr);
node_t* free_entire_linked_list(node_t* headptr);

void print_linked_list(node_t* headptr);
