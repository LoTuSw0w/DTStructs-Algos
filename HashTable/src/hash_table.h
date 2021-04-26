//struct for table item and table
typedef struct
{
    char *key;
    char *value;
} table_item;

typedef struct
{
    int size;
    int count;
    table_item **items;
} hash_table;


//function prototypes

static table_item* ht_new_item(const char* k , const char* v);
hash_table* ht_new_table();
static void ht_delete_item(table_item* i);
void ht_delete_table(hash_table* ht);
static int ht_hash_func(const char* s, const int a, const int modNumber);