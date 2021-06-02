#include "NodeStruct.h"

Node *Initialize_linked_list(int firstValue);
void Traverse_linked_list(Node *root);
Node *Insert_item_to_head(Node **root, int new_value);
Node *Insert_item_to_end(Node *root, int new_value);
int Delete_final_node(Node *root);
int Delete_first_node(Node **root);
int Delete_node_by_value(Node **root, int value_to_delete);