#include <stdio.h>
#include <stdlib.h>

#include "NodeStruct.h"

Node *Initialize_linked_list(int firstValue)
{
    /*create a new pointer as the root, then create a new node
    After that, point the pointer to the node. Finally, return the pointer*/

    Node *rootPointer;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = firstValue;
    new_node->nextNode = NULL;

    rootPointer = new_node;
    return rootPointer;
}

void Traverse_linked_list(Node *root)
{
    //start from the root pointer, the while loop prints the content of each node

    int index = 0;
    Node *tempNode = root;
    printf("Traverse and print the list: ");
    while (tempNode != NULL)
    {
        printf("[ %d ] - ", tempNode->value);
        tempNode = tempNode->nextNode;
        index++;
    }
    printf("\n=> There are %d node(s) in the linked list!\n\n", index);
}

Node *Insert_item_to_head(Node **root, int new_value)
{
    /*create a new node, then point it to the former first node
    after that, point the root pointer to the new first node*/

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->nextNode = *root;
    *root = new_node;

    printf("Insert to head: %d\n\n", new_value);

    return new_node;
}

Node *Insert_item_to_end(Node *root, int new_value)
{
    Node *currentNode = root;

    //Find the last item in the linked list

    while (currentNode->nextNode != NULL)
    {
        currentNode = currentNode->nextNode;
    }

    //allocate new space in the heap for the new node, then provide it with values
    currentNode->nextNode = (Node *)malloc(sizeof(Node));
    currentNode->nextNode->value = new_value;
    currentNode->nextNode->nextNode = NULL;

    printf("Insert to end: %d\n\n", new_value);

    return currentNode->nextNode;
}

int Delete_final_node(Node *root)
{
    Node *currentNode = root;
    int return_value;

    //if there is only a node in the linked list, just remove it

    if (currentNode->nextNode == NULL)
    {
        return_value = currentNode->value;
        printf("Delete at end: %d\n\n", currentNode->value);
        free(currentNode);
        return return_value;
    }

    //go to the second to last node in the linked list

    while (currentNode->nextNode->nextNode != NULL)
    {
        currentNode = currentNode->nextNode;
    }

    //free the last node and point the second to last node to NULL, then return the last node's value

    return_value = currentNode->nextNode->value;
    free(currentNode->nextNode);
    currentNode->nextNode = NULL;
    printf("Delete at end: %d\n\n", return_value);
    return return_value;
}

int Delete_first_node(Node **root)
{
    Node *currentNode = *root;
    int return_value;

    //if there is only a node in the linked list, then remove it

    if (currentNode->nextNode == NULL)
    {
        return_value = currentNode->value;
        printf("Delete at first: %d\n\n", return_value);
        free(currentNode);
        return return_value;
    }

    /*get the second node from the list, then point the pointer to it.
    After that, free the deleted node then return the confirmation value*/

    Node *new_first_node = currentNode->nextNode;
    *root = new_first_node;

    //get the deleted node's value, then free it and return it's value
    return_value = currentNode->value;
    free(currentNode);
    printf("Delete at first: %d\n\n", return_value);
    return return_value;
}

int Delete_node_by_value(Node **root, int value_to_delete)
{
    Node *currentNode = *root;
    int return_value;

    //find the node stand before the node to be deleted

    while (currentNode->nextNode->value != value_to_delete)
    {
        currentNode = currentNode->nextNode;

        //if we reach the end of the list and found no matching value then just return -9999
        if (currentNode->nextNode == NULL && currentNode->value != value_to_delete)
        {
            printf("Delete by value: No node with the value %d was deleted!\n\n", value_to_delete);
            return -9999;
        }
    }

    /*get the node standing after the to-be-deleted node, then point the node 
    in the previous step to it*/

    Node *to_be_deleted_node = currentNode->nextNode;
    Node *new_next_node = currentNode->nextNode->nextNode;
    currentNode->nextNode = new_next_node;

    //get the value of the deleted node, then free it and return that value

    return_value = to_be_deleted_node->value;
    free(to_be_deleted_node);
    printf("Delete by value: The node with value %d was deleted\n\n", return_value);
    return return_value;
}