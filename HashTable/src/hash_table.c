#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

#define HASH_PRIME_1 171
#define HASH_PRIME_2 157

//////////////
//Main
//////////////

int main(void)
{
    int testing = check_prime(7);
    printf("%d", testing);
    return 0;
}

////////////////////////////
//Initializing new hash table item and table
////////////////////////////

static table_item *ht_new_item(const char *k, const char *v)
{
    table_item *i = malloc(sizeof(table_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

hash_table *ht_new_table()
{
    hash_table *table = malloc(sizeof(hash_table));

    table->size = 53;
    table->count = 0;
    table->items = calloc((size_t)table->size, sizeof(table_item *));
}

////////////////////////////
//Deleting hash table item and table
////////////////////////////

static void ht_delete_item(table_item *i)
{
    free(i->value);
    free(i->key);
    free(i);
}

void ht_delete_table(hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        table_item *item = ht->items[i];
        if (item != NULL)
        {
            ht_delete_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

////////////////////////////
//Hash table operations (search, insert, delete, update)
////////////////////////////

//I will point the "deleted" item to this variable to indicate that the item was deleted
static table_item DELETED_ITEM = {NULL, NULL};

//return 1 on insert, 0 on update
int ht_insert(hash_table *ht, const char *key, const char *value)
{
    table_item *item = ht_new_item(key, value);            //create a new item
    int index = ht_double_hashing(item->key, ht->size, 0); //get the first index using hash
    //check if the index belong to a NULL value in the ht->items array
    table_item *cur_item = ht->items[index];
    int i = 1;
    
    while (cur_item != NULL)
    {
        if (cur_item != &DELETED_ITEM)
        {
            if(strcmp(cur_item->key, key) == 0){
                ht_delete_item(cur_item);
                ht->items[index] = item;
                return 0;
            }
        }
        index = ht_double_hashing(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    //else, put the item in the NULL index and increment the count of the table
    ht->items[index] = item;
    ht->count++;
    return 1;
}

char *ht_search(hash_table *ht, const char *key)
{
    int index = ht_double_hashing(key, ht->size, 0); //get the index after the hash
    table_item *item = ht->items[index];
    //move through the chain until finding a NOT-NULL item
    int i = 1;
    while (item != NULL)
    {
        if (item != &DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                return item->value; //return the item if they match the search parameter
            }
        }
        index = ht_double_hashing(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    //return null after iterating through the chain, finding no match for the parameter
    return NULL;
}

/*since I am using open addressing, deleting an item will unfortunately break 
the chain of insert and search. Therefore, I will simply mark an item as "deleted"
to maintain the chain*/

//return 1 on delete, 0 if there is no match
int ht_delete(hash_table *ht, const char *key)
{
    int index = ht_double_hashing(key, ht->size, 0); //get the index after the hash
    table_item *item = ht->items[index];
    //move through the chain until finding a NOT-NULL item
    int i = 1;
    while (item != NULL)
    {
        if (item != &DELETED_ITEM)
        {
            //if match, delete the note by pointing it to the DELETED_ITEM and free the memory
            if (strcmp(key, item->key) == 0)
            {
                ht_delete_item(item);
                ht->items[index] = &DELETED_ITEM;
                //decrease the count
                ht->count--;
                return 1;
            }
        }
        //move through the chain
        index = ht_double_hashing(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    if (item == NULL) //if item is null, then it does not exist 
    {
        return 0;
    }
}

////////////////////////////
//Hash function
////////////////////////////

//generic hash function
static int ht_hash_func(const char *s, const int a, const int bucket)
{
    long hash = 0;
    const int string_length = strlen(s);
    for (int i = 0; i < string_length; i++)
    {
        hash += (long)pow(a, string_length - (i + 1)) * s[i];
        hash = hash % bucket;
    }
    return (int)hash;
}

//double hashing
static int ht_double_hashing(const char *s, const int bucket, const int attempt)
{
    const int first_hash = ht_hash_func(s, HASH_PRIME_1, bucket);
    const int second_hash = ht_hash_func(s, HASH_PRIME_2, bucket);
    return (first_hash + (attempt * (second_hash + 1))) % bucket;
}

//////////////////////////
//calculate prime
//////////////////////////

int check_prime(const int number){
    //base case since 1 and 2 are prime
    if(number <= 2) return 1;
    //check from 3 to number - 1
    for(int i = 3; i < number; i++){
        if(number % i == 0) return 0;
    }
    //the number is a prime if it passes the for loop check
    return 1;
}

//get the prime number next to the number in the parameter
int get_next_prime(int number){
    while(check_prime(number) != 1){
        number++;
    }
    return number;
}