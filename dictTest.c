#include "DataStructures.h"

#include <stdio.h>
#include <string.h>

// make DataStructures
// previous command  creates DataStructures/libDataStructures.a
// gcc -L$(pwd)/DataStructures -lDataStructures  -o dictTest dictTest.c
int main() {
    struct Dictionary my_dict = dictionary_constructor(compare_string_keys);

    char * key1 = "empId";
    char * value1 = "54235";

    char * key2 = "name";
    char * value2 = "Armando Hernández Marin";

    char * key3 = "salary";
    double value3 = 89000.50; 

 
    my_dict.insert(&my_dict, key1, strlen(key1), value1, strlen(value1));
    my_dict.insert(&my_dict, key2, strlen(key2), value2, strlen(value2));
    my_dict.insert(&my_dict, key3, strlen(key3), &value3, sizeof(value3));

    char * empId = (char *) my_dict.search(&my_dict, key1, strlen(key1));
    char * name = (char *) my_dict.search(&my_dict, key2, strlen(key2));
    double salary = * (double *) my_dict.search(&my_dict, key3, strlen(key3));
    printf("empId=%s\n", empId);
    printf("name=%s\n",  name );
    printf("salary=%.2f\n",  salary );
}

