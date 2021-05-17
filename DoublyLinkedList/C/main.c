#include <stdio.h>
#include <stdlib.h>

#include "NodeStruct.h"

void Traverse_root_to_end(Node *root_pointer)
{
    /*assign a temp node, which started at the root pointer, then traverse
    the linked list through the nodes one by one and print their values until reaching NULL*/

    Node *temp_node = root_pointer;
    while (temp_node != NULL)
    {
        printf("- [%d] -", temp_node->value);
        temp_node = temp_node->next_node;
    }
}

void Traverse_end_to_root(Node *end_pointer)
{
    /*Just like the previous function, we apply the same logic but in reverse order*/

    Node *temp_node = end_pointer;
    while (temp_node != NULL)
    {
        printf("- [%d] -", temp_node->value);
        temp_node = temp_node->prev_node;
    }
}

Node *Add_to_front(Node **front_pointer, int new_value)
{
    /*Create a new node and give it the value as indicated in the parameter, then insert it to
    the front of the list by modifying the pointer properties of it and the original first node.
    Naturally, we also need to update the value of the front pointer*/

    //Allocate space for the new node and give it the value as in the parameter
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = new_value;

    //modify the new node's prev_node and next_node pointer. After that, change the prev_node of front_pointer
    new_node->prev_node = NULL;
    new_node->next_node = *front_pointer;
    (*front_pointer)->prev_node = new_node;

    //modify the value of our front pointer then return a pointer to the new node
    *front_pointer = new_node;
    return new_node;
}

Node *Add_to_end(Node **end_pointer, int new_value)
{
    /*Just like the function Add_to_front(), but now we will modify the end pointer instead of 
    the front pointer. The procedure is the same to the aforementioned function*/

    //Allocate the space for the new node and give it the value as in the parameter
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = new_value;

    //Modify the new node's prev_node and next_node pointer
    new_node->next_node = NULL;
    new_node->prev_node = *end_pointer;
    (*end_pointer)->next_node = new_node;

    //Modify the value of the end pointer then return a pointer to the new node
    *end_pointer = new_node;
    return new_node;
}

Node *Find_Node_with_value(int value, Node *root_pointer, Node *end_pointer)
{
    /*We find a value in the list by traverse both ways. By this, it would be faster!
    As soon as a value is found, we can return a pointer to that node*/

    //if either the value is at the start or the end of the list, we can just return them
    if(root_pointer->value == value)
    {
        return root_pointer;
    }
    if(end_pointer->value == value)
    {
        return end_pointer;
    }

    //assign two pointers to two temp nodes
    Node *temp_root = root_pointer;
    Node *temp_end = end_pointer;

    //while their values does not match, keep looping until we find the value, then break the loop.
    while (temp_root->value != value && temp_end->value != value)
    {
        temp_root = temp_root->next_node;
        temp_end = temp_end->prev_node;

        //as soon as the loop is broken, we can decide which node to return
        if (temp_root->value == value)
        {
            return temp_root;
        }
        if (temp_end->value == value)
        {
            return temp_end;
        }

        //conditions to confirm that we have traversed the list and find no matching value, return NULL as a result
        if (temp_root->next_node == temp_end || temp_end->prev_node == temp_root || temp_root->value == temp_end->value)
        {
            puts("no value found!");
            return NULL;
        }
    }
}


void Delete_Node_end(Node* end_pointer)
{

}

void Delete_Node_root(Node* root_pointer)
{

}

void Delete_Node_with_value(int value, Node *root_pointer, Node *end_pointer)
{
    Node *to_be_deleted = Find_Node_with_value(value, root_pointer, end_pointer);
    if (to_be_deleted == NULL)
    {
        puts("Deletion failed! No node matched!");
    }
    else
    {
        Node *next_neighbor = to_be_deleted->next_node;
        Node *prev_neighbor = to_be_deleted->prev_node;

        next_neighbor->prev_node = prev_neighbor;
        prev_neighbor->next_node = next_neighbor;

        free(to_be_deleted);
    }
}

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
    Delete_Node_with_value(6, root_pointer, end_pointer);
    Traverse_root_to_end(root_pointer);

    return 0;
}