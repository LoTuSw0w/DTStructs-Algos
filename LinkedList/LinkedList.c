#include <stdlib.h>
#include <stdio.h>

#include "Functions-header.h"

int main()
{
    Node *rootNode = Initialize_linked_list(2);

    Insert_item_to_end(rootNode, 3);
    Insert_item_to_end(rootNode, 4);
    Insert_item_to_end(rootNode, 5);
    Insert_item_to_end(rootNode, 6);
    Insert_item_to_end(rootNode, 7);
    Insert_item_to_head(&rootNode, 0);
    Insert_item_to_head(&rootNode, -1);
    Insert_item_to_head(&rootNode, 1);
    Traverse_linked_list(rootNode);
    Delete_node_by_value(&rootNode, -23);
    Traverse_linked_list(rootNode);

    printf("Press ENTER key to Continue\n");  
    getchar(); 

    return 0;
}
