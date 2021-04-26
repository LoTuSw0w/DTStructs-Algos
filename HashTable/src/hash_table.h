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

/////////////
//function prototypes
/////////////

//instantiate new item and table
static table_item* ht_new_item(const char* k , const char* v);
hash_table* ht_new_table();

//delete item and table
static void ht_delete_item(table_item* i);
void ht_delete_table(hash_table* ht);

//hashing functions
static int ht_hash_func(const char* s, const int a, const int modNumber);
static int ht_double_hashing(const char* s, const int bucket, const int attempt);

//CRUD operations 


//prime number functions
int check_prime(const int number);
int get_next_prime(int number);