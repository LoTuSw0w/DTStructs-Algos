#include <stdio.h>
#include <stdlib.h>

#include "Function-headers.h"

int main()
{
    Node *root_pointer;
    Node *end_pointer;
    Node first_node;
    Node second_node;

    first_node.value = 1;
    second_node.value = 2;

    first_node.next_node = &second_node;
    first_node.prev_node = NULL;

    second_node.next_node = NULL;
    second_node.prev_node = &first_node;

    root_pointer = &first_node;
    end_pointer = &second_node;

    Add_to_front(&root_pointer, 0);
    Add_to_end(&end_pointer, 3);
    Add_to_end(&end_pointer, 4);
    Add_to_end(&end_pointer, 5);
    Add_to_end(&end_pointer, 6);
    Add_to_end(&end_pointer, 7);
    Delete_Node_with_value(7, &root_pointer, &end_pointer);
    Delete_Node_with_value(0, &root_pointer, &end_pointer);
    Traverse_root_to_end(root_pointer);

    printf("\n\nPress ENTER key to Continue\n");  
    getchar(); 

    return 0;
}