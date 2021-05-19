/*
This struct represents the structure of a singly linked list. Each node 
contains a pointer refering to the next node and an integer representing its value
*/

/*
Use tag NODE to indicate to the compiler that we want this pointer to refer 
to another instance of the same structure
*/

typedef struct NODE
{
    struct NODE *nextNode;
    int value;
} Node;
