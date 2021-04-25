//storing key-value item using a struct
typedef struct table_item
{
    char* key;
    char* value;
};

typedef struct hash_table_properties
{
    int size;
    int count;
    table_item** items;
};

