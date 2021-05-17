#include "NodeStruct.h"

void Traverse_root_to_end(Node *root_pointer);
void Traverse_end_to_root(Node *end_pointer);
Node *Add_to_front(Node **front_pointer, int new_value);
Node *Add_to_end(Node **end_pointer, int new_value);
Node *Find_Node_with_value(int value, Node *root_pointer, Node *end_pointer);
int Delete_Node_end(Node **end_pointer);
int Delete_Node_root(Node **root_pointer);
int Delete_Node_with_value(int value, Node **root_pointer, Node **end_pointer);
