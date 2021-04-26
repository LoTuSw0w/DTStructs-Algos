#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

//////////////
//Main
//////////////

int main(void){
    int testing = ht_hash_func("cat", 151, 53);
    printf("%d", testing);
    return 0;
}


//////////////
//Initializing new hash table item and table
//////////////

static table_item* ht_new_item(const char* k , const char* v){
    table_item* i = malloc(sizeof(table_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

hash_table* ht_new_table(){
    hash_table* table = malloc(sizeof(hash_table));

    table->size = 53;
    table->count = 0;
    table->items = calloc((size_t)table->size, sizeof(table_item*));
}

//////////////
//Deleting hash table item and table
//////////////

static void ht_delete_item(table_item* i){
    free(i->value);
    free(i->key);
    free(i);
}

void ht_delete_table(hash_table* ht){
   for(int i = 0; i< ht->size; i++){
       table_item* item = ht->items[i];
       if(item != NULL){
           ht_delete_item(item);
       }
   }
   free(ht->items);
   free(ht);
}

//////////////
//Hash function
//////////////

static int ht_hash_func(const char* s, const int a, const int modNumber){
    long hash = 0;
    const int string_length = strlen(s);
    for(int i = 0; i < string_length; i++){
        hash += (long)pow(a,string_length - (i+1)) * s[i];
        hash = hash % modNumber;
    }
    return (int)hash;
}