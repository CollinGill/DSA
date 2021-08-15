#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A hash function is any function that can be used to map data of arbitrary size to
// fixed-size values. These values are then typically used to index a fixed-size table
// called a hash table

// Hash functions may be considered to perform three functions:
//      Convert variable-length keys into fixed length values by folding them by words
//          or other units using a parity-perserving operator like ADD or XOR
//      Scramble the bits of the key so that the resulting values are uniformily 
//          distributed over the keyspace
//      Map the key values into ones less than or equal to the size of the table
// Traits of a good hashing function:
//      It should be fast to compute
//      It should minimize duplication of collisions
int hashFunction(const char* string)
{
    int res = 0;
    int i;
    const int hashConstant = 31;

    for (i = 0; *string != '\0'; string++, i++)
    {
        // Multiplying a constant by the total up to this point and adding to the 
        // ASCII value of the current character will create a unique hash value
        res = hashConstant * res + (int)*string;
    }    

    return res;
}

int main()
{
    printf("Please enter a key: \n");
    char* input = (char*)malloc(sizeof(char*));
    scanf("%s", input);

    int hashValue = hashFunction(input);

    printf("Key:\n\t%d\n", hashValue);

    return 0;
}