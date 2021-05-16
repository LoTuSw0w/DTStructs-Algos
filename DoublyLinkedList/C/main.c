#include <stdio.h>
#include <stdlib.h>

#include "NodeStruct.h"

void Traverse_root_to_end(Node* root_pointer)
{
    /*assign a temp node, which started at the root pointer, then traverse
    the linked list through the nodes one by one and print their values until reaching NULL*/

    Node* temp_node = root_pointer;
    while(temp_node != NULL)
    {
        printf("- [%d] -", temp_node->value);
        temp_node = temp_node->next_node;
    }
}

Node* Add_to_front(Node** front_pointer, int new_value)
{
    /*Create a new node and give it the value as indicated in the parameter, then insert it to
    the front of the list by modifying the pointer properties of it and the original first node.
    Naturally, we also need to update the value of the front pointer*/

    //Allocate space for the new node and give it the value as in the parameter
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = new_value;

    //modify the new node's prev_node and next_node pointer. After that, change the prev_node of front_pointer
    new_node->prev_node = NULL;
    new_node->next_node = *front_pointer;
    (*front_pointer)->prev_node = new_node;

    //modify the value of our front pointer then return a pointer to the new node
    *front_pointer = new_node;
    return new_node;
}

Node* Add_to_end(Node** end_pointer, int new_value)
{
    /*Just like the function Add_to_front(), but now we will modify the end pointer instead of 
    the front pointer. The procedure is the same to the aforementioned function*/

    //Allocate the space for the new node and give it the value as in the parameter
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = new_value;

    //Modify the new node's prev_node and next_node pointer
    new_node->next_node = NULL;
    new_node->prev_node = *end_pointer;
    (*end_pointer)->next_node = new_node;

    //Modify the value of the end pointer then return a pointer to the new node
    *end_pointer = new_node;
    return new_node;
}

int main()
{
    Node* root_pointer;
    Node* end_pointer;
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
    Traverse_root_to_end(root_pointer);

    return 0;
}